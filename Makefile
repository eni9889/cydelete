BUNDLEDIR=/Library/MobileSubstrate/DynamicLibraries
BUNDLENAME=CyDelete.bundle
VERSION:=$(shell grep Version layout/DEBIAN/control | cut -d' ' -f2)

LDFLAGS:=-framework UIKit
CFLAGS:=-DBUNDLE="@\"$(BUNDLEDIR)/$(BUNDLENAME)\"" -DVERSION="$(VERSION)"

PWD:=$(shell pwd)
TOP_DIR:=$(PWD)
FRAMEWORKDIR=$(TOP_DIR)/framework
tweak:=CyDelete
subdirs:=preferences
include $(FRAMEWORKDIR)/makefiles/MSMakefile

project-all: setuid

setuid:
	$(CC) $(CFLAGS) -o setuid setuid.c
	$(STRIP) -x setuid
	CODESIGN_ALLOCATE=$(CODESIGN_ALLOCATE) ldid -S $@

project-clean:
	rm -f setuid

project-package-local:
	cp preferences/CyDeleteSettings _/System/Library/PreferenceBundles/CyDeleteSettings.bundle/
	cp setuid _/usr/libexec/cydelete
	rm _$(BUNDLEDIR)/$(BUNDLENAME)/convert.sh
	$(FW_SCRIPTDIR)/plistkey.py _/System/Library/PreferenceBundles/CyDeleteSettings.bundle/Info.plist CFBundleShortVersionString $(VERSION)
	$(FW_SCRIPTDIR)/plistkey.py _/Library/MobileSubstrate/DynamicLibraries/CyDelete.bundle/Info.plist CFBundleShortVersionString $(VERSION)

project-package-post:
	-find _ -iname '*.plist' -print0 | xargs -0 /home/dustin/bin/plutil -convert binary1
	-find _ -iname '*.strings' -print0 | xargs -0 /home/dustin/bin/plutil -convert binary1
	$(FAKEROOT) chown -R 0:80 _
	$(FAKEROOT) chmod 6755 _/usr/libexec/cydelete/setuid

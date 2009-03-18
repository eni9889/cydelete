#import <UIKit/UIKit.h>
#import <UIKit/UIWindow.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIAlert.h>
#import <UIKit/UIScreen.h>
#import <UIKit/UIProgressHUD.h>
#import <UIKit/UIActivityIndicatorView.h>
#import <Foundation/Foundation.h>
#import "SpringBoard/SBIcon.h"
#import "SpringBoard/SBIconController.h"
#import "SpringBoard/SBApplicationController.h"
#import "SpringBoard/SBApplication.h"
#import <objc/runtime.h>
#import "substrate.h"

@protocol CyDelete

- (BOOL)__OriginalMethodPrefix_allowsCloseBox;
- (void)__OriginalMethodPrefix_closeBoxClicked:(id)fp8;
@end

NSMutableString *__CyDelete_outputForShellCommand(NSString *cmd);
static BOOL __$CyDelete_allowsCloseBox(SBIcon<CyDelete> *_SBIcon);
static void __$CyDelete_closeBoxClicked(SBIcon<CyDelete> *_SBIcon, id fp8);
extern "C" void CyDeleteInitialize();

@interface CyDelete : NSObject<UIAlertViewDelegate> {
	SBIcon *_SBIcon;
	NSString *_pkgName;
	NSString *_path;
	UIProgressHUD *_hud;
	UIWindow *_win;
	NSInteger _finish;
}
- (void)startHUD:(id)message;
- (void)killHUD;
+ (NSInteger)getFinish:(NSString *)text;
+ (NSString *)getFinishString:(NSInteger)finish;
- (id)initWithIcon:(SBIcon *)icon path:(NSString *)path;
- (void)_closeBoxClicked;
- (void)closeBoxClicked_thread:(id)callingThread;
- (void)closeBoxClicked_finish:(id)dpkgOutput;
- (void)askDelete;
- (void)alertSheet:(UIActionSheet *)alertSheet buttonClicked:(NSInteger)buttonIndex;
- (void)_uninstall;
- (void)uninstall_thread:(NSThread *)callingThread;
- (void)uninstalled:(NSString *)body;
- (void)notifyFinish;
- (void)finishUninstall;
- dealloc;
@end
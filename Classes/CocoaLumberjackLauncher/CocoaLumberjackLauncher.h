//
//  CocoaLumberjackLauncher.h
//
//  Created by Yu Sugawara on 4/17/15.
//  Copyright (c) 2015 Yu Sugawara. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CocoaLumberjack/CocoaLumberjack.h>

/**
 ## Usage
 
 ### Launch logger
 
 Launch Xcode console logger and Apple system logger.
 
 ```
 [CocoaLumberjackLauncher launchStandardLoggers];
 ```
 
 ### Dynamically changing log levels
 
 ```
 [CocoaLumberjackLauncher changeStandardLoggersLevel:DDLogLevelWarning];
 ```
 
 ### Set Xcode console log colors
 ```
 [CocoaLumberjackLauncher setXcodeConsoleLogColorsWithErrorColor:[UIColor redColor]
 warningColor:[UIColor yellowColor]
 infoColor:[UIColor darkGrayColor]
 debugColor:[UIColor greenColor]
 verboseColor:nil];
 ```
 ### Show console in app
 
 ```
 [CocoaLumberjackLauncher showAppConsole];
 ```
 
 ## Tips
 
 ### Force synchronous logging
 
 ```
 #if defined(LOG_ASYNC_ENABLED)
 #undef LOG_ASYNC_ENABLED
 #define LOG_ASYNC_ENABLED NO
 #endif
 ```
 */

NS_ASSUME_NONNULL_BEGIN
@interface CocoaLumberjackLauncher : NSObject

///-------------
/// @name Launch
///-------------

+ (void)launchStandardLoggers;
+ (void)launchStandardLoggersWithLevel:(DDLogLevel)level;

///---------------
/// @name Log Level
///---------------

+ (void)changeStandardLoggersLevel:(DDLogLevel)level;
+ (DDLogLevel)standardLoggersLogLevel;

+ (void)changeAppConsoleLoggerLevel:(DDLogLevel)level;
+ (DDLogLevel)appConsoleLoggerLevel;

///------------
/// @name Color
///------------

+ (void)setXcodeConsoleLogColorsWithErrorColor:(UIColor * __nullable)errorColor
                                  warningColor:(UIColor * __nullable)warningColor
                                     infoColor:(UIColor * __nullable)infoColor
                                    debugColor:(UIColor * __nullable)debugColor
                                  verboseColor:(UIColor * __nullable)verboseColor;

///------------------
/// @name App Console
///------------------

+ (void)showAppConsole;
+ (void)showAppConsoleWithLevel:(DDLogLevel)level;

+ (void)hideAppConsole;

@end

///---------------
/// @name Function
///---------------

extern NSString *NSStringFromDDLogLevel(DDLogLevel level);

///------------
/// @name Macro
///------------

#define dd_func_str(frmt, ...) dd_func_str_w(self, frmt, ##__VA_ARGS__)

#define dd_func_str_w(wself, frmt, ...) ^NSString*(){\
NSMutableString *log = [NSString stringWithFormat:@"-[%@ %@](%d)(%p)", NSStringFromClass([wself class]), NSStringFromSelector(_cmd), __LINE__, wself].mutableCopy;\
if (frmt) {\
[log appendFormat:@" %@", [NSString stringWithFormat:frmt, ##__VA_ARGS__]];\
}\
return [NSString stringWithString:log];\
}()

#define dd_func_error(frmt, ...) DDLogError(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_error_w(wself, frmt, ...) DDLogError(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_error_pre(pre, frmt, ...) DDLogError(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_error_pre_w(wself, pre, frmt, ...) DDLogError(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_warn(frmt, ...) DDLogWarn(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_warn_w(wself, frmt, ...) DDLogWarn(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_warn_pre(pre, frmt, ...) DDLogWarn(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_warn_pre_w(wself, pre, frmt, ...) DDLogWarn(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_debug(frmt, ...) DDLogDebug(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_debug_w(wself, frmt, ...) DDLogDebug(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_debug_pre(pre, frmt, ...) DDLogDebug(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_debug_pre_w(wself, pre, frmt, ...) DDLogDebug(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_info(frmt, ...) DDLogInfo(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_info_w(wself, frmt, ...) DDLogInfo(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_info_pre(pre, frmt, ...) DDLogInfo(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_info_pre_w(wself, pre, frmt, ...) DDLogInfo(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_verbose(frmt, ...) DDLogVerbose(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_verbose_w(wself, frmt, ...) DDLogVerbose(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_verbose_pre(pre, frmt, ...) DDLogVerbose(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_verbose_pre_w(wself, pre, frmt, ...) DDLogVerbose(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

NS_ASSUME_NONNULL_END
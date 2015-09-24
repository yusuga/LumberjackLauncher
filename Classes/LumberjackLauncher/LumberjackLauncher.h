//
//  LumberjackLauncher.h
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
 [LumberjackLauncher launchStandardLoggers];
 ```
 
 ### Dynamically changing log levels
 
 ```
 [LumberjackLauncher changeStandardLoggersLevel:DDLogLevelWarning];
 ```
 
 ### Set Xcode console log colors
 ```
 [LumberjackLauncher setXcodeConsoleLogColorsWithErrorColor:[UIColor redColor]
 warningColor:[UIColor yellowColor]
 infoColor:[UIColor darkGrayColor]
 debugColor:[UIColor greenColor]
 verboseColor:nil];
 ```
 ### Show console in app
 
 ```
 [LumberjackLauncher showAppConsole];
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
@interface LumberjackLauncher : NSObject

///-------------
/// @name Launch
///-------------

+ (void)launchStandardLoggers;
+ (void)launchStandardLoggersWithLevel:(DDLogLevel)level;

///----------------
/// @name Log Level
///----------------

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

NS_ASSUME_NONNULL_END
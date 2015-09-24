//
//  ViewController.m
//  LumberjackLauncherExample
//
//  Created by Yu Sugawara on 4/17/15.
//  Copyright (c) 2015 Yu Sugawara. All rights reserved.
//

#import "ViewController.h"
#import "LumberjackLauncher.h"
#import "LumberjackLauncherMacros.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [LumberjackLauncher launchStandardLoggers];
    
    [LumberjackLauncher setXcodeConsoleLogColorsWithErrorColor:[UIColor redColor]
                                                  warningColor:[UIColor yellowColor]
                                                     infoColor:[UIColor darkGrayColor]
                                                    debugColor:[UIColor greenColor]
                                                  verboseColor:nil];
    dd_func_debug_pre(@"Launch Standard Loggers!", nil);
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    dd_func_info(nil);
}

- (void)viewDidAppear:(BOOL)animated
{
    dd_func_info(nil);
}

- (IBAction)logLevelControlDidChange:(UISegmentedControl *)sender
{
    DDLogLevel logLevel;
    switch ((int)sender.selectedSegmentIndex) {
        case 5:
            logLevel = DDLogLevelVerbose;
            break;
        case 4:
            logLevel = DDLogLevelDebug;
            break;
        case 3:
            logLevel = DDLogLevelInfo;
            break;
        case 2:
            logLevel = DDLogLevelWarning;
            break;
        case 1:
            logLevel = DDLogLevelError;
            break;
        case 0:
        default:
            logLevel = DDLogLevelOff;
            break;
    }
    
    [LumberjackLauncher changeStandardLoggersLevel:logLevel];
    [LumberjackLauncher changeAppConsoleLoggerLevel:logLevel];
    
    NSLog(@"Change log level = %@", NSStringFromDDLogLevel([LumberjackLauncher standardLoggersLogLevel]));
}

- (IBAction)log
{
    NSLog(@"Log level = %@", NSStringFromDDLogLevel([LumberjackLauncher standardLoggersLogLevel]));
    DDLogError(@"DDLogError");
    DDLogWarn(@"DDLogWarn");
    DDLogInfo(@"DDLogInfo");
    DDLogDebug(@"DDLogDebug");
    DDLogVerbose(@"DDLogVerbose");
    printf("\n\n\n");
}

- (IBAction)toggleConsole:(UISwitch *)sender
{
    if (sender.on) {
        [LumberjackLauncher showAppConsole];
        NSLog(@"App console log level = %@\n", NSStringFromDDLogLevel([LumberjackLauncher appConsoleLoggerLevel]));
    } else {
        [LumberjackLauncher hideAppConsole];
    }
}

@end

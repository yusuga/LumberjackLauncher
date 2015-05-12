//
//  LumberjackLauncher.m
//
//  Created by Yu Sugawara on 4/17/15.
//  Copyright (c) 2015 Yu Sugawara. All rights reserved.
//

#import "LumberjackLauncher.h"
#import <LumberjackConsole/PTEDashboard.h>
#import <LumberjackConsole/PTEConsoleLogger.h>

NSString *NSStringFromDDLogLevel(DDLogLevel level)
{
    switch (level) {
        case DDLogLevelOff:
            return @"DDLogLevelOff";
        case DDLogLevelError:
            return @"DDLogLevelError";
        case DDLogLevelWarning:
            return @"DDLogLevelWarning";
        case DDLogLevelInfo:
            return @"DDLogLevelInfo";
        case DDLogLevelDebug:
            return @"DDLogLevelDebug";
        case DDLogLevelVerbose:
            return @"DDLogLevelVerbose";
        case DDLogLevelAll:
            return @"DDLogLevelAll";
        default:
            return [NSString stringWithFormat:@"Unknown DDLogLevel(%zd)", level];
            break;
    }
}

NS_ASSUME_NONNULL_BEGIN
@implementation LumberjackLauncher

static DDLogLevel __standardLoggersLogLevel = DDLogLevelAll;
static DDLogLevel __appConsoleLoggerLogLevel = DDLogLevelAll;
static PTEConsoleLogger *__appConsoleLogger;

#pragma mark - Initialize

+ (void)initialize
{
    if (self == [LumberjackLauncher class]) {
        /**
         * Enables XcodeColors (you obviously have to install it too)
         * Note: The XcodeColors is necessary before add logger
         */
        setenv("XcodeColors", "YES", 0);
        
        [[self xcodeConsoleLogger] setColorsEnabled:YES];
    }
}

#pragma mark - Launch

+ (void)launchStandardLoggers
{
    [self launchStandardLoggersWithLevel:DDLogLevelAll];
}

+ (void)launchStandardLoggersWithLevel:(DDLogLevel)level
{
    __standardLoggersLogLevel = level;
    for (id<DDLogger> logger in [self standardLoggers]) {
        [DDLog addLogger:logger withLevel:level];
    }
}

#pragma mark - LogLevel

+ (void)changeStandardLoggersLevel:(DDLogLevel)level
{
    for (id<DDLogger> logger in [self standardLoggers]) {
        [DDLog removeLogger:logger];
    }
    
    [self launchStandardLoggersWithLevel:level];
}

+ (DDLogLevel)standardLoggersLogLevel
{
    return __standardLoggersLogLevel;
}

+ (void)changeAppConsoleLoggerLevel:(DDLogLevel)level
{
    if (![self appConsoleLogger]) return ;
    
    __appConsoleLoggerLogLevel = level;
    
    [DDLog removeLogger:[self appConsoleLogger]];
    [DDLog addLogger:[self appConsoleLogger] withLevel:level];
}

+ (DDLogLevel)appConsoleLoggerLevel
{
    return __appConsoleLoggerLogLevel;
}

#pragma mark - Color

+ (void)setXcodeConsoleLogColorsWithErrorColor:(UIColor * __nullable)errorColor
                                  warningColor:(UIColor * __nullable)warningColor
                                     infoColor:(UIColor * __nullable)infoColor
                                    debugColor:(UIColor * __nullable)debugColor
                                  verboseColor:(UIColor * __nullable)verboseColor
{
    DDTTYLogger *logger = [self xcodeConsoleLogger];
    [logger setColorsEnabled:YES];
    
    if (errorColor) [logger setForegroundColor:errorColor backgroundColor:nil forFlag:DDLogFlagError];
    if (warningColor) [logger setForegroundColor:warningColor backgroundColor:nil forFlag:DDLogFlagWarning];
    if (infoColor) [logger setForegroundColor:infoColor backgroundColor:nil forFlag:DDLogFlagInfo];
    if (debugColor) [logger setForegroundColor:debugColor backgroundColor:nil forFlag:DDLogFlagDebug];
    if (verboseColor) [logger setForegroundColor:verboseColor backgroundColor:nil forFlag:DDLogFlagVerbose];
}

#pragma mark - App Console

+ (void)showAppConsole
{
    [self showAppConsoleWithLevel:[self standardLoggersLogLevel]];
}

+ (void)showAppConsoleWithLevel:(DDLogLevel)level
{
    [[PTEDashboard sharedDashboard] show];
    
    if (![self appConsoleLogger]) {
        // Search PTEConsoleLogger
        for (id<DDLogger> logger in [DDLog allLoggers]) {
            if ([logger isKindOfClass:[PTEConsoleLogger class]]) {
                __appConsoleLogger = (id)logger;
                break;
            }
        }
    }
    
    [self changeAppConsoleLoggerLevel:level];
}

+ (void)hideAppConsole
{
    [PTEDashboard sharedDashboard].hidden = YES;
}

#pragma mark - Private

+ (NSArray *)standardLoggers
{
    return @[[self xcodeConsoleLogger], [self appleSystemLogger]];
}

+ (DDTTYLogger *)xcodeConsoleLogger
{
    return [DDTTYLogger sharedInstance];
}

+ (DDASLLogger *)appleSystemLogger
{
    return [DDASLLogger sharedInstance];
}

+ (PTEConsoleLogger *)appConsoleLogger
{
    return __appConsoleLogger;
}

@end
NS_ASSUME_NONNULL_END
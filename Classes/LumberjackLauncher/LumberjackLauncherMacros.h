//
//  LumberjackLauncherMacros.h
//  LumberjackLauncherExample
//
//  Created by Yu Sugawara on 9/24/15.
//  Copyright © 2015 Yu Sugawara. All rights reserved.
//

#define dd_func_str(frmt, ...) dd_func_str_w(self, frmt, ##__VA_ARGS__)

#define dd_func_str_w(wself, frmt, ...) ^NSString *(id obj, NSString *format, ...){\
    NSMutableString *log = [NSString stringWithFormat:@"-[%@ %@](%d)(%p)", NSStringFromClass([obj class]), NSStringFromSelector(_cmd), __LINE__, obj].mutableCopy;\
    if (format) {\
        va_list ap;\
        va_start(ap, format);\
        [log appendString:[[NSString alloc] initWithFormat:format arguments:ap]];\
        va_end(ap);\
    }\
    return [NSString stringWithString:log];\
}(wself, frmt, ##__VA_ARGS__)

#define dd_func_error(frmt, ...)                        DDLogError(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_error_w(wself, frmt, ...)               DDLogError(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_error_pre(pre, frmt, ...)               DDLogError(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_error_pre_w(wself, pre, frmt, ...)      DDLogError(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_warn(frmt, ...)                         DDLogWarn(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_warn_w(wself, frmt, ...)                DDLogWarn(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_warn_pre(pre, frmt, ...)                DDLogWarn(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_warn_pre_w(wself, pre, frmt, ...)       DDLogWarn(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_debug(frmt, ...)                        DDLogDebug(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_debug_w(wself, frmt, ...)               DDLogDebug(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_debug_pre(pre, frmt, ...)               DDLogDebug(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_debug_pre_w(wself, pre, frmt, ...)      DDLogDebug(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_info(frmt, ...)                         DDLogInfo(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_info_w(wself, frmt, ...)                DDLogInfo(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_info_pre(pre, frmt, ...)                DDLogInfo(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_info_pre_w(wself, pre, frmt, ...)       DDLogInfo(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))

#define dd_func_verbose(frmt, ...)                      DDLogVerbose(@"%@", dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_verbose_w(wself, frmt, ...)             DDLogVerbose(@"%@", dd_func_str_w(wself, frmt, ##__VA_ARGS__))
#define dd_func_verbose_pre(pre, frmt, ...)             DDLogVerbose(@"%@ %@", pre, dd_func_str(frmt, ##__VA_ARGS__))
#define dd_func_verbose_pre_w(wself, pre, frmt, ...)    DDLogVerbose(@"%@ %@", pre, dd_func_str_w(wself, frmt, ##__VA_ARGS__))
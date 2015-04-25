# CocoaLumberjackLauncher

Very simple [CocoaLumberjack](https://github.com/CocoaLumberjack/CocoaLumberjack) launcher.

## Features

- Support [CocoaLumberjack](https://github.com/CocoaLumberjack/CocoaLumberjack)

  - DDTTYLogger(Xcode console logger)
  - DDASLLogger(Apple system logger)
  
- Support [LumberjackConsole](https://github.com/PTEz/LumberjackConsole)
- Support [XcodeColors](https://github.com/robbiehanson/XcodeColors)
- Dynamically changing log levels.

## Installation

```
pod 'CocoaLumberjackLauncher', :git => 'https://github.com/yusuga/CocoaLumberjackLauncher.git'
```

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

### Show/Hide console in app

```
[CocoaLumberjackLauncher showAppConsole];
[CocoaLumberjackLauncher hideAppConsole];
```

## Tips

### Force synchronous logging

```
#if defined(LOG_ASYNC_ENABLED)
#undef LOG_ASYNC_ENABLED
#define LOG_ASYNC_ENABLED NO
#endif
```

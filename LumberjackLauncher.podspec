Pod::Spec.new do |s|
  s.name = 'LumberjackLauncher'
  s.version = '0.0.1'
  s.summary = 'Very simple CocoaLumberjack launcher.'
  s.homepage = 'https://github.com/yusuga/LumberjackLauncher'
  s.license = 'MIT'
  s.author = 'Yu Sugawara'
  s.source = { :git => 'https://github.com/yusuga/LumberjackLauncher.git', :tag => s.version.to_s }
  s.platform = :ios, '7.0'
  s.ios.deployment_target = '7.0'
  s.source_files = 'Classes/LumberjackLauncher/*.{h,m}'
  s.requires_arc = true 
  
  s.dependency 'CocoaLumberjack', '~> 2.0.0'
  s.dependency 'LumberjackConsole'
end
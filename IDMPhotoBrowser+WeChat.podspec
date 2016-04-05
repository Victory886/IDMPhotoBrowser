Pod::Spec.new do |s|
  s.name          =  "IDMPhotoBrowser+WeChat"
  s.summary       =  "**Modified the effects like WeChat**Photo Browser / Viewer inspired by Facebook's and Tweetbot's with ARC support, swipe-to-dismiss, image progress and more."
  s.version       =  "1.9.7"
  s.homepage      =  "https://github.com/yehuanwen/IDMPhotoBrowser"
  s.license       =  { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author        =  { "yehuanwen" => "yehuanwen@126.com" }
  s.source        =  { :git => "https://github.com/yehuanwen/IDMPhotoBrowser.git", :tag => "1.9.7" }
  s.platform      =  :ios, '7.0'
  s.source_files  =  'Classes/*.{h,m}'
  s.resources     =  'Classes/IDMPhotoBrowser.bundle', 'Classes/IDMPBLocalizations.bundle'
  s.framework     =  'MessageUI', 'QuartzCore', 'SystemConfiguration', 'MobileCoreServices', 'Security'
  s.requires_arc  =  true
  s.dependency       'SDWebImage'
  s.dependency       'DACircularProgress'
  s.dependency       'pop'
  end

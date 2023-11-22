Pod::Spec.new do |s|
  
  # 名称、版本号、概述
  s.name             = 'PublicTools'
  s.version          = '1.0.0'
  s.summary          = '自用公共类仓库'

  # 详细描述
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  # 主页、截图、license证书、作者信息、源代码地址、社交地址
  s.homepage         = 'https://github.com/LXHugh/PublicTools.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'xxx' => '13511029398@163.com' }
  s.source           = { :git => 'https://github.com/LXHugh/PublicTools.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  # iOS版本
  s.ios.deployment_target = '9.0'

  # 源码所在路径
  s.source_files = 'PublicTools/Class/PublicToolHeader.h'
  
  # 资源文件所在地址
  # s.resource_bundles = {
  #   'TestLib' => ['TestLib/Assets/*.png']
  # }

  # 对外公开的h文件地址，swift一般用不到
  # s.public_header_files = 'Pod/Classes/**/*.h'
  
  # 包含的系统framework
  # s.frameworks = 'UIKit', 'MapKit'
  
  # 包含的第三方pod
  # s.dependency 'AFNetworking', '~> 2.3'
end

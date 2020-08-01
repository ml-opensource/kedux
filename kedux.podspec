Pod::Spec.new do |s|
    s.name = "kedux"
    s.version = "0.0.1"
    s.summary = "amazeballs libaray"
    s.description = <<-DESC
                          this is a test for integrations with KMP code bases
                    DESC
  
    s.homepage = "https://fuzz.pro"
    s.license = 'MIT'
    s.author = { "Nick Trienens" => "nick@fuzzproductions.com" }
    s.source = { :git => "git@github.com:monstar-lab-oss/kedux.git", :tag => s.version.to_s }
  
    s.ios.frameworks = 'UIKit', 'Foundation'
    s.ios.deployment_target  = '11.0'
    s.requires_arc = true
    s.default_subspecs = "development"
  
    s.subspec 'development' do |dev|
      dev.vendored_frameworks = 'podsource/debug/*'
    end
    s.subspec 'release' do |dev|
        dev.vendored_frameworks = 'podsource/release/app.framework'
      end
  end
  
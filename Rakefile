abort('Please run this using `bundle exec rake`') unless ENV['BUNDLE_BIN_PATH']
require 'html-proofer'
desc 'Test the website'
task :test => [] do
  options = {
      :check_sri => true,
      :check_external_hash => true,
      :check_html => true,
      :check_img_http => true,
      :check_opengraph => true,
      :http_status_ignore => [999]
      # Some of the links do not support HTTPS, not much we can do to fix them.
      # :enforce_https => true
  }
  begin
    HTMLProofer.check_directory('./_site/', options).run
  rescue => message
    puts "#{message}"
  end
end

task :default => [:test]

source 'https://rubygems.org'

require 'json'
require 'open-uri'
versions = JSON.parse(URI('https://pages.github.com/versions.json').open.read)

gem 'github-pages', versions['github-pages']
gem 'jekyll-paginate'
gem 'jekyll-sitemap'
gem 'jekyll-seo-tag'

group :test do
  gem 'rake'
  gem 'html-proofer'
end

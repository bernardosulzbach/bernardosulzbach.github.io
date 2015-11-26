pcregrep\
  --files-without-match\
  -M\
  '\-\-\-\nlayout: .*\ntitle: .*\n(tags: .*\n)?\-\-\-\n\n'\
  *.md

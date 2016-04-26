# This script converts old highlights from GH to the new syntax
sed -i.bak -r 's/^\{% highlight ([a-z]+) %\}/```\1/g' **/*.md
sed -i.bak -r 's/^\{% endhighlight %\}/```/g' **/*.md

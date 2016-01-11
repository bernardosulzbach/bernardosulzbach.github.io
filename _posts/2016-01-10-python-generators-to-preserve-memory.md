---
layout: post
title: "Python: use generators to preserve memory"
---

Even though this feature is not new at all, very few seem to use
generators as much as they should. Generators may help one write
programs that require less memory to run when compared to their list
comprehension analogous.

Let me use a trivial example to demonstrate the difference. Real-world
examples may involve more complicated number crunching but will have
a very similar structure and also present the same improvements.

Problem: determine the sum of the first ten thousand perfect squares

## Solution using list comprehension

{% highlight python %}
sum([n ** n for n in range(10 ** 4)])
{% endhighlight %}

## Solution using a generator

{% highlight python %}
sum((n ** n for n in range(10 ** 4)))
{% endhighlight %}

In this case, refactoring is very simple, but usually you would have
the list comprehension result assigned to a variable and used later on.
It's up to the developer to spot scenarios where a list comprehension
may be replaced by a generator.

The list, in its entirety, takes 79.28 MiB on my machine, whilst the
bigger value produced by the generator takes only 17.33 KiB. As you
would expect, the results are identical.

## Determining the size of a list in memory

If you don't know about it yet, there is a nice tool called pympler that
allows you to measure the memory size of collections. See the snippet
below.

{% highlight python %}
from pympler.asizeof import asizeof


print(asizeof(list_of_perfect_squares))  # 84 134 440 -> 79.28 MiB
{% endhighlight %}

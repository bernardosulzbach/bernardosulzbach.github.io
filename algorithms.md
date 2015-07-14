---
layout: page
title: Algorithms
---

# Euclid's Algorithm (GCD)
{% highlight cpp %}
N gcd(N a, N b) {
    while (a %= b) {
        swap(a, b);
    } 
    return b;
}
{% endhighlight %}

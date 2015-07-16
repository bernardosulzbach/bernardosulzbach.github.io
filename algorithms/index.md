---
layout: page
title: Algorithms
tags: [sidebar]
---

# Euclid's algorithm

Finds the greatest common divisor (GCD) between two integers.

{% highlight cpp %}
N gcd(N a, N b) {
    while (a %= b) {
        swap(a, b);
    }
    return b;
}
{% endhighlight %}

# Brian Kernighan's algorithm

Finds how many set bits there are in an integer.

{% highlight cpp %}
int count_set_bits(unsigned u) {
    int count = 0;
    while (u) { // Will loop until u has no more set bits.
        u &= u - 1;
        count++;
    }
    return count;
}
{% endhighlight %}
## Explanation

Subtracting one from an unsigned integer toggles all bits until the rightmost
set one (`10111000` – `00000001` = `10110111`).

Therefore, the result of a bitwise and operation between `n` and `n – 1`, is
`n` with the rightmost set bit unset. For instance, `10111000 & 10110111 =
1011000`.

If `n` has `x` set bits, it will take `x` operations to make `n = 0`.

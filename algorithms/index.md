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

# Brent's Algorithm

This algorithm detects whether a singly linked list has a cycle in linear time.
It uses a moving rabbit and a stationary, then teleporting (at powers of two), turtle.
Both turtle and rabbit start at the first node of the list.
Each iteration moves rabbit one node forward.
If it is then at the same position as the stationary turtle, there is obviously a loop.
If it reaches the end of the list, there is no loop.

Lambda denotes the length of the loop.
It keeps track of how many steps the rabbit took since we last teleported the turtle.

Mu denotes the index of the element where the loop starts, to find it, we reset the turtle to the first element of the list and the rabbit to lambda elements after the mu.
When the rabbit and the turtle meet, the turtle is at mu.

{% highlight python %}
    def brent(first_node):
        """
        Detects a loop in a linked list in O(n) time and O(1) space complexity.
    
        Returns a tuple of the form (mu, la), where
            mu denotes the index of the list where the loop starts and
            la is the length of the loop.
    
        If this list does not have a loop, this function returns (-1, -1).
        """
        power = 1  # The power of two we are working with.
        la = 1
        turtle = first_node
        rabbit = first_node.next
        while rabbit is not None and rabbit != turtle:
            if la == power:  # Get the next power of two if lambda is big enough.
                la = 0
                power *= 2
                turtle = rabbit
            rabbit = rabbit.next
            la += 1
        if rabbit == turtle:  # Determine where the loop starts.
            mu = 0
            turtle = rabbit = first_node
            for _ in range(la):  # Let the rabbit advance λ nodes (a full cycle).
                rabbit = rabbit.next
            while rabbit != turtle:  # Increment both until they meet.
                turtle = turtle.next
                rabbit = rabbit.next
                mu += 1
            return mu, la
        else:
            return -1, -1
{% endhighlight %}

# Andrew's monotone chain for convex hulls

Too big to be here. Got [its own page](/algorithms/andrew-monotone-chain-for-convex-hulls/).

# Fisher–Yates shuffling algorithm

This is a simple implementation of one of the best shuffling algorithms out
there. The Fisher-Yates shuffling algorithm is **unbiased** (every permutation
is equally likely), runs in **linear time**, and requires **constant space**.

The algorithm logic is quite simple: start from one of the ends of the array and
pick one random element from the unsorted part of the array (including the
current element) and swap it with the current element until the opposite end is
reached. This is my implementation of the abovementioned algorithm in Java.

{% highlight java %}
public static void shuffle(List<?> list) {
    for (int i = list.size() - 1; i > 0; i--) {
        int index = (int) (Math.random() * (i + 1));
        Collections.swap(list, i, index);
    }
}
{% endhighlight %}

Note, however, that you can use Collections.shuffle(List). This is usually a
Fisher-Yates implementation.

# Miscellaneous

[Find the smallest difference between lists](/algorithms/smallest-difference-between-lists/).
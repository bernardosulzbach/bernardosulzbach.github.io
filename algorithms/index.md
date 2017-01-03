---
layout: page
title: Algorithms
tags: [sidebar]
---

# My algorithms repository

[This](https://github.com/mafagafogigante/algorithms) is my
public algorithms and data structures repository at GitHub. Feel free to
inspect my code and propose, or submit, any changes you want.

# Rope

A rope (or cord) is a data structure composed of smaller strings that is used
for efficiently storing and manipulating a very big piece of text. Text editors
may make use of this data structure so that insertions and deletions performed
by the user can be done efficiently.

See more about it on [its own page]({{ site.baseurl }}/algorithms/rope/).

# Euclid's algorithm

Finds the greatest common divisor (GCD) between two integers.

```cpp
N gcd(N a, N b) {
    while (a %= b) {
        swap(a, b);
    }
    return b;
}
```

# Brian Kernighan's algorithm

Finds how many set bits there are in an integer.

```cpp
int count_set_bits(unsigned u) {
    int count = 0;
    while (u) { // Will loop until u has no more set bits.
        u &= u - 1;
        count++;
    }
    return count;
}
```

## Explanation

Subtracting one from an unsigned integer toggles all bits until the rightmost
set one (`10111000` – `00000001` = `10110111`).

Therefore, the result of a bitwise and operation between `n` and `n – 1`, is
`n` with the rightmost set bit unset. For instance, `10111000 & 10110111 =
1011000`.

If `n` has `x` set bits, it will take `x` operations to make `n = 0`.

# Finding the number of digits of a factorial

If the argument is not too big, this can easily be solved by using logarithms.

See that the number of digits of `n!` is `ceil(log10(n!))` for all positive `n`.

By definition,

    n! = n * (n - 1) * ... * 1

Therefore,

    log(n!) = log(n) + log(n - 1) + ... + log(1)

Therefore, a simple and fast solution in Python is:

```python
def factorial_digit_count(n):
    return ceil(sum(log10(x) for x in range(1, n + 1)))
```

> Note: I have tested this solution with inputs as big as 1M (1,000,000,000) and it gives a correct result. If you determine its limits, please let me know. Also, feel free to share any performance improvements you think I am missing.

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

```python
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
```

# Longest common subsequence (LCS)

## Description

The longest common subsequence problem is the problem of finding the longest
subsequence common to all sequences of a set of sequences. A subsequence is any
ordered subset of a sequence. Therefore, AC is a subsequence of ABC.

This is a classic problem of computer science and is solved to generate useful
difference lists between files by version control systems.

Here I will present the intuition behind the solution of the algorithm for the
case where the sequence set has only two sequences.

## Complexity

For an arbitrary number of sequences the problem is NP-hard and for two
sequences the dynamic programming solution has both time and space complexity of
O(n × m).

## The algorithm

The dynamic programming solution can be understood by a recursive definition:

    LCS(X[:i], Y[:j]) =
        0                                                   if i == 0 or j == 0
        LCS(X[:i - 1], Y[:j - 1]) + 1                       if X[i] == Y[j]
        max(LCS(X[:i], Y[:j - 1]), LCS(X[:i - 1], Y[:j]))   otherwise

If X<sub>i</sub> = Y<sub>j</sub>, the LCS is the LCS of the prefixes (up to, but
not including, the last elements) plus one (to account for the new common
element).

Otherwise, do not account for the last element into the LCS and take the longest
of the two possible candidates.

## Implementation

The simplest way to implement the dynamic programming solution based on the
abovementioned recursive solution uses a matrix where each element corresponds
to the longest common subsequence up to that point.

# Longest common substring

The longest common substring problem is quite similar to the longest common
subsequence problem. It differs because the definition of a substring is
different to that of a subsequence as it does not include non-contiguous
subsequences. Therefore, AC is a subsequence of ABC, but not a substring. AB,
for instance, is both a substring and a subsequence of ABC.

The recursive solution is similar to that of the LCS problem. The only change is
that instead of taking the maximum of the two possible candidates when there is
a mismatch, one should use zero. This is because there can be no mismatches in
the middle of a substring.

# Monotone chain for convex hulls

Too big to be here. Got [its own page]({{ site.baseurl }}/algorithms/andrew-monotone-chain-for-convex-hulls/).

# Fisher–Yates shuffling algorithm

This is a must-known shuffling algorithm. [It has its own page]({{ site.baseurl }}/algorithms/fisher-yates/).

# String matching

[String matching page]({{ site.baseurl }}/algorithms/string-matching/).

# String similarity

[Levenshtein distance page]({{ site.baseurl }}/algorithms/levenshtein-distance/).

# Sorting

[Sorting page]({{ site.baseurl }}/algorithms/sorting/).

# Miscellaneous

[Find the smallest difference between lists]({{ site.baseurl }}/algorithms/smallest-difference-between-lists/).

[Reservoir sampling]({{ site.baseurl }}/algorithms/reservoir-sampling/).

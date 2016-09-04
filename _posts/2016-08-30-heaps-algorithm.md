---
layout: post
title: Heap’s Algorithm
---

In this post, I describe an alternative to the [Narayana Pandita's algorithm]({{
site.baseurl }}/lexicographic-permutations/), an algorithm used to generate
permutations of a set of elements which I have already written about.

# Comparison with the alternative

This is one of the most efficient ways to generate the permutations of a list.
It is more efficient than the [Narayana Pandita's algorithm]({{ site.baseurl
}}/lexicographic-permutations/) if both are properly implemented.

This algorithm does not generate permutations in lexicographic order, which is
required in some scenarios.

This algorithm does not require any comparison between elements of the list it
is sorting, making it more appealing for sequences without defined order or
whose elements are difficult to compare.

# Python implementations

Based on implementations found on the Internet, I wrote two PEP 8 compliant
Python 3 versions of Heap's algorithm. The first one, which is also the most
elegant one in my opinion, is a recursive implementation. As one may assume, the
cost of the several levels of recursion make it substantially more expensive
than it needs to be.

## Recursive implementation

```python
{% include code/heaps_algorithm_recursive.py %}
```

> This code uses the `yield from` syntax, added in Python 3.3. You can [read
> more about it here](https://docs.python.org/3/whatsnew/3.3.html#pep-380-syntax-for-delegating-to-a-subgenerator).

The algorithm is not trivially understood. Essentially, what is happening is a
locking of the rightmost element and the recursive permutation of all other
elements, then an intelligently chosen swap involving the rightmost element and
the repetition of the process until all elements have been in the rightmost
position.

## Non-recursive implementation

```python
{% include code/heaps_algorithm_non_recursive.py %}
```

## Benchmarking

I have benchmarked the algorithm for lexicographic permutations and both
implementations above using a sequence of 10 integers and a sequence of 10
strings of 100 characters which only differed by the last character. Note that
although an input of length 10 may seem small for an unaware reader, there are
10! = 3,628,800 results generated even for such small input.

The benchmarking results follow.

    Lexicographic with 10 integers took 10.99 seconds.
    Recursive Heap's with 10 integers took 14.10 seconds.
    Non-recursive Heap's with 10 integers took 4.29 seconds.

    Lexicographic with 10 strings took 11.66 seconds.
    Recursive Heap's with 10 strings took 14.43 seconds.
    Non-recursive Heap's with 10 strings took 4.31 seconds.

As you can see, the cost of recursion makes the more elegant implementation of
Heap's algorithm even slower than the lexicographic permutation generator.
However, the non-recursive implementation is substantially more efficient. It is
also visible from these numbers that the performance hit from the use of big
strings (which are more expensive to compare than small integers) was bigger on
the lexicographic permutation generator than on the generators that do not
compare elements.

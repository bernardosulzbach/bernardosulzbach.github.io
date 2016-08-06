---
layout: post
title: Lexicographic Permutations
---

This post describes how to generate the lexicographic permutations of a
sequence. The **lexicographic order** is a generalization of the way the
alphabetical order of words is based on the alphabetical order of their
component letters. This generalization consists primarily in defining a total
order over the sequences of elements of a finite totally ordered set. You may
understand that this is a way to establish ordering between sequences based on
how their elements compare.

# Algorithm description

There exist several ways to generate all permutations of a given sequence. The
simple algorithm which I will discuss here is based on finding the next
permutation in lexicographic ordering, if it exists, or reversing the last
permutation to get back to the minimal permutation. This method goes back to
[Narayana Pandita](https://en.wikipedia.org/wiki/Narayana_Pandit) in 14th
century India.

The algorithm is quite straightforward and may be memorized:

    Find the biggest i such that a[i] > a[i + 1];
    Find the biggest j such that a[j] > a[i];
    Swap a[i] and a[j];
    Reverse the elements from a[i + 1] to the last element.

Given any permutation of a list, this generates the next one. It should be
noted, however, that when given the greatest lexicographic permutation, this
algorithm returns this same permutation, so it should be checked to ensure that
if the permutation at hand is the last one, we reverse the sequence to get back
to the first permutation.

This algorithm is simple to implement correctly, computationally efficient, and
it only generates each distinct permutation once, which is convenient when there
are many repeated elements.

# Python implementation

Below is an in-place Python 3 implementation of the described algorithm. If you
do not want mutability, wrap the algorithm calls with a function that copies the
list. However, take into consideration that for very large lists this may use a
significant amount of memory if you are interested in several permutations.

```python
def swap(elements, i, j):
    elements[i], elements[j] = elements[j], elements[i]


def reverse(elements, i, j):
    for offset in range((j - i + 1) // 2):
        swap(elements, i + offset, j - offset)


def next_permutation(elements):
    last_index = len(elements) - 1
    if last_index < 1:
        return elements

    i = last_index - 1
    while i >= 0 and not elements[i] < elements[i + 1]:
        i -= 1

    # If there is no greater permutation, return to the first one.
    if i < 0:
        reverse(elements, 0, last_index)
    else:
        j = last_index
        while j > i + 1 and not elements[j] > elements[i]:
            j -= 1

        swap(elements, i, j)
        reverse(elements, i + 1, last_index)
```

You can also get it as a [source file]({{ site.baseurl
}}/assets/lexicographic-permutations.py).

Documentation was omitted for the sake of brevity. One could also consider this
an example of [code as
documentation](http://martinfowler.com/bliki/CodeAsDocumentation.html).

## Algorithm output

Generating eight permutations of the string 'abc' in ascending lexicographic
order produces the following sequence:

```
abc, acb, bac, bca, cab, cba, abc, acb, ...
```

Notice that after the sixth permutation we get back to the first one, as there
are only six distinct permutations of the string 'abc'.

## Algorithm complexity

This algorithm uses constant additional space (as it is in-place) and has linear
time complexity in the worst case but is amortized to constant time.

---
layout: page
title: Fisher–Yates shuffling algorithm
---

This is a simple implementation of one of the best shuffling algorithms out
there. The Fisher-Yates shuffling algorithm is **unbiased** (every permutation
is equally likely), runs in **linear time**, and requires **constant space**.

The algorithm logic is quite simple: start from one of the ends of the array and
pick one random element from the unsorted part of the array (including the
current element) and swap it with the current element until the opposite end is
reached. This is my implementation of the abovementioned algorithm in Java.

```java
public static void shuffle(List<?> list) {
    for (int i = list.size() - 1; i > 0; i--) {
        int index = (int) (Math.random() * (i + 1));
        Collections.swap(list, i, index);
    }
}
```

With Java you can use
[Collections.shuffle(List)](http://docs.oracle.com/javase/8/docs/api/java/util/Collections.html#shuffle-java.util.List-)
which is usually a Fisher–Yates implementation.

## Random permutations

It should be clear without saying, but this algorithm can be used to generate
random permutations of the elements of a list (that's what shuffling means). If
you are looking for all permutations in random order without repetition, you
could use either [Heap's algorithm]({{ site.baseurl }}/heaps-algorithm/) or
[Narayana Pandita's algorithm]({{ site.baseurl }}/lexicographic-permutations/)
and shuffle the resulting permutation list with Fisher–Yates.

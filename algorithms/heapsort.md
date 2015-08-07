---
layout: page
title: Heapsort
---

# Introduction

This is a short tutorial on the heapsort algorithm. Heapsort is great: it is
simple to program and has worst-case `O(n log n)` (the best that can be
expected from a sorting algorithm). It is also an example of how a data
structure can make dramatic algorithmic improvements. **Heapsort can be thought
as a variation of selection sort that uses a [priority
queue](https://en.wikipedia.org/wiki/Priority_queue "Wikipedia article") to
speed up the process**.

# Selection sort

Just in case you do not know selection sort, this is a decent pseudocode
representation of it:

    selection_sort(a)
        for i from 1 to a.length
           sorted[i] = find_minimum(a)
           delete_minimum(a)
        return(sorted)

## Analysis

Removing an item from an unsorted array – given its index – takes constant time
(because you can write the last element over the element you wish to remove and
reduce the length by one in constant time), whilst finding the minimum of an
unsorted array takes `O(n)` time (through linear search). This makes selection
sort a `O(n²)` average-case algorithm, as it finds the minimum **n** times.

Some data structures provide these operations with better time complexities.
**Heaps** and **balanced binary trees** (these are not _abstract_ data
structures, such as the aforementioned priority queue) provide both operations
with `O(lg n)` time complexity, making the sorting algorithm (that operates on
**n** elements) take `O(n lg n)` time.

# Heaps

Heaps work by maintaining a partial order of the elements, which is weaker than
the sorted order (so it is easier to maintain) yet stronger than random order
(so the minimum element can be quickly identified). A min heap establishes that
the parent node has a smaller value than its children, while the parent nodes
of a max heap dominate by being bigger.

Heaps are slick data structures that enable us to represent binary trees
without using pointers. Specifically, a heap is usually represented as an array
where the positions of the keys implicitly take the roles of pointers. If we
are using a zero-indexed array, the n-th level of the tree starts in the
**2<sup>n-1</sup> – 1** element and ends at the **2<sup>n</sup> – 2** element.
The root is stored in the first position of the array and its left and right
children in the second and third. This way, the first child of the node at `k`
is at `2(k + 1) – 1` and the parent of the node at `k` lies at `⌊(k - 1) / 2⌋`.
Clearly, this is one of those cases where discarding the first element of the
array makes the implementation simpler in exchange of a few bytes of memory.

## Size

Any binary tree can be stored in an array without the use of pointers. The
downside is that sparse trees end up occupying huge amounts of space as
“missing” nodes still take up space. Space efficiency demands that each level
is as dense as it can be. Therefore, only the last level may be incomplete. It
is possible to store a tree of **n** keys using an array of exactly **n**
elements (as long as all the elements of the last level are packed to the
left).

Representing binary trees using this structure saves memory, but does not allow
some _tricks_ such as moving a subtree around by manipulating a single pointer.
This illustrates why arrays are not a good representation for binary search
trees, but a great representation for heaps.

## Construction

Incremental insertion is the simplest way to construct heaps. Inserting the new
element in the leftmost empty position of the array ensures that the shape of
the tree is correct, but may violate the right ordering of keys. To solve this
problem, some children nodes may need to be swapped with their parents in a
process known as _bubbling up_.

## Getting the minimum or maximum

Identifying the dominant element is as simple as getting the first element of
the underlying array. To fill the hole left by the removal of the first element
the rightmost leaf can be used. The new root may eventually be dominated by its
children. In order to fix this, the new root may be swapped with its children
until it dominates all its children, perhaps by becoming a leaf (in a process
know as _bubbling down_). This operation is sometimes called **heapify**, as it
merges two heaps – the subtrees below the old root – with a new key.

## Faster construction

There is a faster way to construct heaps than incremental insertion. The core
idea is that, after getting **n** keys to construct a heap from, we just insert
them at the beginning of the array. This makes the right shape for our array
(it is not sparse), but the dominance order may be completely wrong. In order
to fix the dominance order, all we need to do is to call the bubble down
procedure to all elements that are not leaves (trivially, all the leaves are
dominant).
This is faster because it can be proven with analysis that all bubble down
calls are bounded by a constant. As the number of bubble down calls is `O(n)`,
this solution is `O(n)`.

# Implementations
[This is my implementation of a priority queue and heapsort using Python 3](https://github.com/mafagafogigante/algorithms-and-data-structures/blob/master/priority-queue/priority_queue.py).

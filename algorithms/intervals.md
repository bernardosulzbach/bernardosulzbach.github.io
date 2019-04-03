---
layout: page
title: "Intervals"
---

Sets of intervals are often represented as a sorted list of integer pairs.

Thorough this page intervals are considered to include both ends.

The Python 3 code examples consider intervals to be lists of two integers.

## Insertion
A common requirement is to be able to insert a new interval into an interval
set. When the new interval does not intersect with any of the existing
intervals this is easy. However, if the number of intersections is not zero,
making mistakes in the insertion logic is common. Therefore, I think it is
worthwhile to present here well-tested code for inserting a new interval into
an interval list.

The implementation presented here requires `O(n)` to find the insertion point,
`O(n)` to insert, `O(n)` to find and merge overlapping intervals, and then
`O(n)` to free the no longer required objects.

It is worth mentioning that even though both search steps can be improved to
`O(lg n)`, inserting into an array-based list and freeing the no longer
required intervals should always be at least `O(n)`, so you should not be able
to do better than `O(n)` asymptotically.

However, if your interval list grows very large, I'd advise using binary search
or some other technique to improve this operation as much as possible.

```python
{% include algorithms/intervals/insert.py %}
```

An adapted version of the above algorithm is able to successfully solve [this
problem on LeetCode](https://leetcode.com/problems/insert-interval/).

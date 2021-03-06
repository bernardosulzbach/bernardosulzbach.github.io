---
layout: page
title: Monotone Chain for Convex Hulls
---

This algorithm finds the convex hull of a set S of points with O(n lg n) time
complexity. The convex hull of a geometric object is the smallest (convex) set
containing that object. In a bidimensional polygon, one can imagine the convex
hull as the format a rubber band  would take if it was released and let snap
around the points.

The naive approach has O(n<sup>3</sup>) time complexity because there are
O(n<sup>2</sup>) pairs of points and O(n) comparisons per pair to ensure that
all other points lie either to the right or to the left of the segment formed by
a given pair. As it is often too slow in practice, I won't waste more characters
about it here.

The O(n lg n) time of this algorithm arises from the need to sort the points. If
your input is already sorted, it becomes a O(n) algorithm.

The algorithm builds the convex hull by first making an upper hull and a lower
hull and then merging both hulls together.

![Illustration]({{ site.baseurl }}/assets/upper-and-lower-convex-hulls.png)
An illustration from [www.algorithmist.com](http://www.algorithmist.com/).

In this example (where the points are sorted first by nondecreasing values of x,
then by nondecreasing values of y), the upper hull starts with the uppermost
leftmost point. Iterating to the right, while the partial hull has two or more
points and the arc formed by the last two points of the hull and the next point
of the ordered set is positively oriented, pop out the last point of the partial
hull. This new point should then be added to the hull.

The code for this procedure is given below.

```python
for p in points:
  while len(upper) >= 2 and cross(upper[-2], upper[-1], p) >= 0:
    upper.pop()
  upper.append(p)
```

cross(o, a, b) here is the cross product of two column vectors (OA and OB). It
is a positive value, if OAB makes a counter-clockwise turn, negative for
clockwise turn, and zero if the points are collinear.

A similar, but vertically mirrored version of the procedure described above is
used to generate the lower hull. In the end, it is a simple matter of combining
both hulls into a single one and returning it.

The complete algorithm is as follows.

```python
{% include code/monotone-chain-for-convex-hulls/code.py %}
```

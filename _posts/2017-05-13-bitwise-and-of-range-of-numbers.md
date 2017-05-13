---
layout: post
title: Bitwise And of Range
---

Recently I had to solve a problem which asked you to determine the bitwise and
of a range of nonnegative numbers. There is an obvious linear solution to this
problem which simply computes the bitwise and of the range.

```
Bitwise and of [4, 10] = 4 & 5 & 6 & 7 & 8 & 9 & 10
```

However, after thinking about how the anding ends up "erasing" bits permanently
I figured out the following logarithmic solution:

```python
{% include code/bitwise_and_of_range.py %}
```

Essentially, if you have at least two numbers in the range, the last bit will be
zero, so you can compute the bitwise and of the prefixes and append a zero to
the result (by shifting it to the left).

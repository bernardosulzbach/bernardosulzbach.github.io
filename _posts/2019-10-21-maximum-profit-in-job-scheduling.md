---
layout: post
title: Maximum Profit in Job Scheduling
description: A solution for the LeetCode problem number 1235, Maximum Profit in Job Scheduling.
---

This is my solution for the LeetCode problem number 1235, [Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/).

This problem is quite similar to that of determining the maximum number of not overlapping ranges.
The only difference is that in this problem the ranges have a profit associated with them, rather than a linear function over the size of the range.

The key idea for my solution, which runs in $$O(n \lg n)$$, is to sort all jobs by their starting time and, going backwards, store the result of the maximum profit when starting at time $$t$$.
For every job that starts at $$t_i$$, the maximum when starting at $$t_i$$ has to be set to either the maximum found for any $$t_j > t_i$$ or the maximum for any $$t_k > e_i$$, where $$e_i$$ is the ending time of the job $$i$$, plus the profit of job $$i$$, whichever is bigger.
This is the optimization of the choice between scheduling job $$i$$ or skipping it.

```cpp
{% include maximum-profit-in-job-scheduling/main.cpp %}
```


---
layout: post
title: Solution to Best Time to Buy and Sell Stock with Cooldown
---


This is my solution for the LeetCode problem number 309, [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/).

This is a quite simple problem which can be addressed in O(1) space and O(n) time using dynamic programming.
However, the O(n) space solution seems easier to arrive at.
The subproblem explored through dynamic programming is that starting day $$i$$ with no stock bought and after the cooldown has ended is equivalent to solving a subproblem which consists of only days $$i$$ through $$n$$.

In this solution, 0 is used to indicate that no stock is owned, 1 is used to indicate that stock is owned and 2 is used to indicate cooldown.
The algorithm keeps three values for each day: the maximum profit by starting without stock, the maximum profit by starting with stock and the maximum profit by starting under cooldown.
After the bottom-up solving is done, the answer to the problem question is what is the maximum profit for starting at the first day without stock.

```cpp
{% include best-time-to-buy-and-sell-stock-with-cooldown/1.cpp %}
```

Now, because evaluating the day $$i$$ only requires information about the day $$i + 1$$, the vector of arrays can become just two arrays, as follows.

```cpp
{% include best-time-to-buy-and-sell-stock-with-cooldown/2.cpp %}
```


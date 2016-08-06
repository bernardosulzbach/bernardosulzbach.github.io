---
layout: post
title: "Concealed Squares"
---

This is my solution to [Project Euler](https://projecteuler.net/) problem number
206. Although a brute force solution can be easily derived, this approach makes
use of mathematical analysis to find the answer in less time. The problem
statement follows.

> Find the unique positive integer whose square has the form
> `1_2_3_4_5_6_7_8_9_0`, where each "`_`" is a single digit.

It can be shown that the answer lies in the range R.

    R = [floor(sqrt(1020304...00)), ceiling(sqrt(192939..90))] = [1010101010, 1389026624]

R has 378,925,614 integers, which is a lot to test quickly. Fortunately, one
can reduce it by noticing that the square of the integer is divisible by 10,
which implies that the integer too is divisible by 10. This leaves us with the
possible solution set P.

    P = {1010101010, 1010101020, ..., 1389026620}

The largest possible number is 19293949596979899990, which requires 65 bits to
be represented as an unsigned integer. However, because we know that the answer
is a multiple of 10, we also know that the square of the answer is a multiple of
100. And, therefore, that it ends with 00. This allows for another optimization:
divide all numbers in P by 10 and find the one whose square is of the form
`1_2_3_4_5_6_7_8_9`. These numbers fit into 64-bit words, so arithmetic with
them will not be specially expensive.

P has 37,892,561 elements, but we do not need to check all of them. If
x<sup>2</sup> ends in 9, x ends in 3 or 7, which reduces by 80% the number of
values we have to test.

Using Clang with the O3 flag, [my C++ implementation]({{ site.baseurl
}}/assets/concealed-squares.cpp) of the algorithm finishes after 120 ms, which
is a good enough solution for this problem.

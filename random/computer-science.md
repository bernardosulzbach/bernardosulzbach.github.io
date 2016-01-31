---
layout: page
title: Theoretical computer science notes
tags: [random]
---

# Turing completeness

A language with numbers, assignments, input, output, comparisons and looping
constructs is considered Turing complete. *This means that if a problem can be
solved via computation, it can be solved with this language*.

# Floating-point numbers

Modern computers use binary, not decimal, number representations. The
significant digits and exponents are represented in binary rather than decimal
and raise 2 rather than 10 to the exponent. For example, the number 0.625 (5/8)
would be represented as the pair (101, -11); because 5 is 101 in binary and -11
is the binary representation of -3, the pair (101, -11) stands for 5 &middot;
2<sup>-3</sup> = 5 / 8 = 0.625.

What about the decimal fraction 1/10, which we write in as 0.1?  The best we
can do with four significant binary digits is (0011, -101).  This is equivalent
to 3/32, i.e., 0.09375.  If we had five significant binary digits, we would
represent 0.1 as (11001, -1000), which is equivalent to 25/256, i.e.,
0.09765625.  How many significant digits would we need to get an exact
floating-point representation of 0.1?  An infinite number of digits! There do
not exist integers `sig` and `exp` such that `sig * 2`<sup>`-exp`</sup> equals
0.1. Therefore, no matter how many bits the language chooses to use to
represent floating point numbers, it will be able to represent only an
approximation of 0.1. In many implementations, there are 53 bits of precision
available for floating point numbers, so the significant digits stored for the
decimal number 0.1 will be

    11001100110011001100110011001100110011001100110011001

This is equivalent to the decimal number

    0.1000000000000000055511151231257827021181583404541015625

Close to 1/10, but not 1/10.


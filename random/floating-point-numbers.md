---
layout: page
title: "Floating point numbers"
tags: [random]
---

Modern computers use binary, not decimal, number representations for numbers
with a decimal part. The significant digits and exponents are represented in
binary rather than decimal and raise 2 rather than 10 to the exponent.

# Standardization

Nearly all modern programming languages use the same binary representation for
floating point numbers, which was set by the IEEE 754 standard. The most popular
floating point number sizes are usually referred to as single precision and
double precision floating points, these numbers use either 32 bits or 64 bits to
represent their values.

# Limitations

Single precision floating point numbers (32 bits) according to the IEEE 754
standard, can represent values from 1.2e-38 to 3.4e+38. Double precision
floating point numbers of the same standard may represent values from 5.0e-324
to 1.8e+308.

# Example of an exact representation

Some numbers may be represented exactly. For instance, the number 0.625 (5/8)
would be represented as the pair (101, -11); because 5 is 101 in binary and -11
is the binary representation of -3, the pair (101, -11) stands for 5 · 2⁻³ = 5 /
8 = 0.625.

# Example of an approximation

What about the decimal fraction 1/10, which we write as 0.1? The best we can do
with four significant binary digits is (0011, -101). This is equivalent to 3/32,
i.e., 0.09375. If we had five significant binary digits, we would represent 0.1
as (11001, -1000), which is equivalent to 25/256, i.e., 0.09765625. How many
significant digits would we need to get an exact floating-point representation
of 0.1? An infinite number of digits. There do not exist integers `sig` and
`exp` such that `sig * 2 ^ -exp` equals 0.1. Therefore, no matter how many bits
the language chooses to use to represent floating point numbers, it will be able
to represent only an approximation of 0.1. In many implementations, there are 53
bits of precision available for floating point numbers, so the significant
digits stored for the decimal number 0.1 will be

    11001100110011001100110011001100110011001100110011001

This allows for the approximation of the decimal number

    0.1000000000000000055511151231257827021181583404541015625

Which is close to 1/10, but not 1/10.


---
layout: page
title: Mathematics
tags: [sidebar]
---

## Significant figures

### Definition
The significant figures of a number are those digits that carry meaning
contributing to its precision. This includes all digits except all leading zeros
and trailing zeros when they are used to indicate the scale of the number.

## Calculations
The result of addition and subtraction should have as many decimal places as the
term with less decimal places.

The result of multiplication and division should have as many significant
figures as the least precise term.

## Rounding
If the first non-significant figure is a 5 not followed by any other digits or
followed only by zeros, rounding requires a tie-breaking rule.

**Round half up** is the default rounding method used in many disciplines if
the tie-breaking rule is not specified. **Round half to even** rounds to the
nearest even number.

## Set Theory

### Power Set
The power set P(S) is the set of all subsets of S, including the empty set and
the set S itself. It has 2<sup>|S|</sup> elements.

## Proofs

### If n² is divisible by a prime p, then n is divisible by p

#### Proof for a specific prime

Before proving the generalized version for all primes, I am going to prove that
this is valid for a small prime. In this case, I've chosen 3. The easiest way I
could find involved proving the contrapositive.

Let us prove that if n is **not** divisible by 3, n² is also **not** divisible
by 3.

If n is not divisible by 3, n may be written as either n = 3k + 1 or n = 3k + 2.

For the first case, n² = 9k² + 6k + 1 = 3(3k² + 2k) + 1, which is not divisible
by 3.

For the second case, n² = 9k² + 12k + 4 = 3(3k² + 4k + 1) + 1, which is also not
divisible by 3. 

This concludes the proof that if n is **not** divisible by 3, n² is also **not**
divisible by 3, which also proves that if n² (n ∈ ℕ) is divisible by 3, n is
divisible by 3.

#### Generalization for all primes

If n² (n ∈ ℕ) is divisible by a prime p, n is divisible by p.

Again, I will prove the contrapositive. If n is **not** divisible by p, n² is
also **not** divisible by p.

If n = pk + q, for a positive q, q < p, then n² = p²k² + 2pkq + q²
Therefore n² = p(pk² + 2kq) + q². As p is a prime, p ∤ q² and therefore n² is
not divisible by p.

This proves that  if n² (n ∈ ℕ) is divisible by a prime p, n is divisible by p.

### The square root of any prime number is irrational

This is a quite short and simple proof. I've noticed that proofs for specific
primes seem to be much more popular. However, the proofs are so similar that it
does not even make sense to prove a specific case instead of the general one.

As one might expect, this is a [proof by reduction to the
impossible](https://en.wikipedia.org/wiki/Reductio_ad_absurdum).

Suppose that the square root of p is a rational number. Therefore there exist
two [mutually prime numbers](https://en.wikipedia.org/wiki/Coprime_integers) a
and b such that the square root of p equals the ratio between a and b.

Therefore, p = a² / b². Then b² p = a², which implies that p divides a², and,
because p is a prime, p divides a. Therefore, b² p = (k² p²), which can be
simplified to b² = k² p. This implies that p divides b², and p divides b, which
is absurd as a and b are mutually prime in our proof.

By reduction to the impossible, this proves that the square root of any prime
number p is an irrational number.

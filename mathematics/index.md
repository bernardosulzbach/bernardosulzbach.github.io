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

### If n<sup>2</sup> is divisible by a prime p, then n is divisible by p

#### Proof for a specific prime

Before proving the generalized version for all primes, I am going to prove that
this is valid for a small prime. In this case, I've chosen 3. The easiest way I
could find involved proving the contrapositive.

Let us prove that if n is **not** divisible by 3, n<sup>2</sup> is also **not**
divisible by 3.

If n is not divisible by 3, n may be written as either n = 3k + 1 or n = 3k + 2.

For the first case, n<sup>2</sup> = 9k<sup>2</sup> + 6k + 1 = 3(3k<sup>2</sup> + 2k) + 1, which is not divisible by 3.

For the second case, n<sup>2</sup> = 9k<sup>2</sup> + 12k + 4 = 3(3k<sup>2</sup> + 4k + 1) + 1, which is also not divisible by 3.

This concludes the proof that if n is **not** divisible by 3, n<sup>2</sup> is
also **not** divisible by 3, which also proves that if n<sup>2</sup> (n ∈ ℕ) is
divisible by 3, n is divisible by 3.

#### Generalization for all primes

If n<sup>2</sup> (n ∈ ℕ) is divisible by a prime p, n is divisible by p.

Again, I will prove the contrapositive. If n is **not** divisible by p,
n<sup>2</sup> is also **not** divisible by p.

If n = pk + q, for a positive q, q < p, then n<sup>2</sup> =
p<sup>2</sup>k<sup>2</sup> + 2pkq + q<sup>2</sup> Therefore n<sup>2</sup> =
p(pk<sup>2</sup> + 2kq) + q<sup>2</sup>. As p is a prime, p ∤ q<sup>2</sup> and
therefore n<sup>2</sup> is not divisible by p.

This proves that if n<sup>2</sup> (n ∈ ℕ) is divisible by a prime p, n is
divisible by p.

### The square root of any prime number is irrational

This is a quite short and simple proof. I've noticed that proofs for specific
primes seem to be much more popular. However, the proofs are so similar that it
does not even make sense to prove a specific case instead of the general one.

As one might expect, this is a [proof by reduction to the
impossible](https://en.wikipedia.org/wiki/Reductio_ad_absurdum).

Suppose that the square root of p is a rational number. Therefore there exist
two [mutually prime numbers](https://en.wikipedia.org/wiki/Coprime_integers) a
and b such that the square root of p equals the ratio between a and b.

Therefore, p = a<sup>2</sup> / b<sup>2</sup>. Then b<sup>2</sup> p =
a<sup>2</sup>, which implies that p divides a<sup>2</sup>, and, because p is a
prime, p divides a. Therefore, b<sup>2</sup> p = (k<sup>2</sup> p<sup>2</sup>),
which can be simplified to b<sup>2</sup> = k<sup>2</sup> p. This implies that p
divides b<sup>2</sup>, and p divides b, which is absurd as a and b are mutually
prime in our proof.

By reduction to the impossible, this proves that the square root of any prime
number p is an irrational number.

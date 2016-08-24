---
layout: post
title: "Balancing Chemical Equations"
---

On this post, I describe an efficient way to balance chemical equations using
linear algebra.

# Procedure

From any chemical equation, we can derive a vector equation that describes the
number of atoms of each element present in the reaction. Row reducing this
vector matrix leads to the general solution, from which we can easily derive a
solution with integer coefficients.

# Example

Find the smallest integer coefficients that balance the following chemical
equation.

  MnS
+ As<sub>2</sub>Cr<sub>10</sub>O<sub>35</sub>
+ H<sub>2</sub>SO<sub>4</sub>
→ HMnO<sub>4</sub>
+ AsH<sub>3</sub>
+ CrS<sub>3</sub>O<sub>12</sub>
+ H<sub>2</sub>O

## Solution

From the chemical equation above, we can derive the following matrix. Notice
that the first row is for Mn, the second is for S, and so on. However, how you
choose to order does not matter, as long as all columns respect the order.

    1    0    0   -1    0    0    0
    1    0    1    0    0   -3    0
    0    2    0    0   -1    0    0
    0   10    0    0    0   -1    0
    0   35    4   -4    0  -12   -1
    0    0    2   -1   -3    0   -2

The last four columns all have negative atom counts because they have been
subtracted from both sides of the original vector equation.

After row reducing the matrix with
[Octave](https://www.gnu.org/software/octave/), we get

    1.00000   0.00000   0.00000   0.00000   0.00000   0.00000  -0.04893
    0.00000   1.00000   0.00000   0.00000   0.00000   0.00000  -0.03976
    0.00000   0.00000   1.00000   0.00000   0.00000   0.00000  -1.14373
    0.00000   0.00000   0.00000   1.00000   0.00000   0.00000  -0.04893
    0.00000   0.00000   0.00000   0.00000   1.00000   0.00000  -0.07951
    0.00000   0.00000   0.00000   0.00000   0.00000   1.00000  -0.39755

However, this is not of much help as we want to end up with integer
coefficients. Therefore, we change the number display format to rational by
using [format rat](https://www.gnu.org/software/octave/doc/v4.0.0/Terminal-Output.html#XREFformat).
This makes the last column six rationals with the same denominator.

     -16/327
     -13/327
    -374/327
     -16/327
     -26/327
    -130/327

After multiplying the last column by 327 and changing its sign, we get the
coefficients for the balanced equation.

     16
     13
    374
     16
     26
    130

Note that the free variable is the coefficient of H<sub>2</sub>O, which is 327
as we are interested on the smallest integer that makes all other coefficients
integers.

Wrapping up, the balanced equation has coefficients 16, 13, 374, 16, 26, 130,
327, in this order. Not something easy to find by trial and error.

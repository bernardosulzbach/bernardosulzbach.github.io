---
layout: post
title: "Obtaining a Boolean Expression from a Truth Table"
---

Producing a truth table from a boolean expression is a trivial task, as you
just need to evaluate the expression for each combination of inputs.

However, the opposite is not so simple.

A way to convert a truth table into a boolean expression is writing an
expression that evaluates to true for each and every row that evaluates to true
and chain them together with the OR operator. This expression may later be
simplified by using logical identities.

Note that this does not give you the **simplest** possible boolean expression,
which is an NP-complete problem.

## Example

Let us obtain a boolean expression from the following truth table

|A|B|C|=|
|-|-|-|-|
|0|0|0|0|
|0|0|1|0|
|0|1|0|0|
|0|1|1|1|
|1|0|0|0|
|1|0|1|1|
|1|1|0|1|
|1|1|1|1|

Step 1 - Write an expression for each row that evaluates to true

    ¬A  AND  B  AND  C
     A  AND ¬B  AND  C
     A  AND  B  AND ¬C
     A  AND  B  AND  C

Step 2 - Join them all with the OR operator

    ¬A  AND  B  AND  C  OR
     A  AND ¬B  AND  C  OR
     A  AND  B  AND ¬C  OR
     A  AND  B  AND  C

Step 3 - Simplify to the best of your ability

    ¬A  AND  B  AND  C  OR
     A  AND ¬B  AND  C  OR
     A  AND  B  AND ¬C  OR
     A  AND  B  AND  C

    -----------------------

    ¬A  AND  B  AND  C  OR
    ¬B  AND  A  AND  C  OR
    ¬C  AND  A  AND  B  OR
     A  AND  B  AND  C

    -----------------------

    (A AND B) OR (A AND C) OR (B AND C)

Your efficiency on step 3 will depend on several factors such as your
persistence, previous practice, and pattern recognition skills.

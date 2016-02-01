---
layout: page
title: Rope
---

A rope (or cord) is a data structure composed of smaller strings that is used
for efficiently storing and manipulating a very big piece of text. Text editors
may make use of this data structure so that insertions and deletions performed
by the user can be done efficiently.

It is a binary tree whose leafs contain strings. Each node is given a weight
value equal to the sum of the weights of its left subtree or the length of its
string, if it is a leaf node.

# Efficiency

## Indexing

Finding a character by its index in a rope is an `O(lg n)` operation, as it
consists of a top-down search on a binary tree.

## Concatenating

Concatenating two ropes together is also a `O(lg n)` operation.

Given two ropes `a` and `b`, concatenating them together is as simple as
creating a new root node and assigning `a` to its left child and `b` to its
right child. However, the root node must descend into the left child to compute
its own weight, making it `O(lg n)`.

## Splitting

Splitting a rope into two is a `O(lg n)` operation as it relies on indexing,
which is sublinear.

## Insertion

Insertion is also `O(lg n)` as it can be done with either one split and two
concatenations or a single concatenation (if prepending or appending the other
rope).

## Deletion

Deletion is yet another `O(lg n)` operation. Deletion can be done with two
splits and one concatenation.

## Reporting

In order to present the data to an user or to save it to a file, it will be
necessary to convert the whole tree, or at least part of it, to a string.  This
is `O(m + lg n)` where `m` is the number of nodes needed to visit, usually
directly proportional to the size of the string we are trying to obtain.  To
convert a rope into a linear string, one needs to find the starting node in
`O(lg n)` and perform an in-order traversal until the last needed node is found
in `O(m)`.

## Comparison with array-based strings

For big text blocks, ropes have faster insertion and deletion than monolithic
arrays and don't require large contiguous memory spaces to exist. The biggest
disadvantage of ropes over arrays is its sheer complexity, which makes the risk
of bugs in your code much higher.

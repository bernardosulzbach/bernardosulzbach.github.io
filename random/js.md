---
layout: page
title: JavaScript notes
tags: [random]
---

## The `delete` operator

The delete operator is a unary operator that removes a named property from an
object. If you set a property to `undefined`, the `in` operator will still
return `true` (as the object still has the property). However, if you delete
it, the `in` operator will return false.

## Array methods

Besides the very popular `push` and `pop` methods, array also have the `shift`
and `unshift` methods, that pop the first element out and insert an element
into the first position, respectively.

# Functions

## Arguments

In JavaScript, you are allowed to pass a function more (or fewer) arguments
than the number of declared parameters.  Inside a function, an `arguments`
object is available. As the name indicated, it is a representation of the
arguments passed to the function. Although it looks like an array, it is not
one, so you cannot call `slice` on it, for instance.



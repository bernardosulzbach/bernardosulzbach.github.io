---
layout: post
title: Finding the Maximum of Four Integers
---

Inspired by an analysis of the source code of
[Rogue](https://en.wikipedia.org/wiki/Rogue_(video_game)), I decided to find
out how clever modern compilers are when it comes down to what the programmer
expressed as a short macro: the selection of the maximum of four integers.

```cpp
#define MAX(a, b, c, d)                                 \
  (a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d))  \
         : (b > c ? (b > d ? b : d) : (c > d ? c : d)))
```

Using Clang 5.0, I get the following (with optimizations enabled, of course).

     0:  39 f7                	cmp    edi,esi
     2:  0f 4d f7             	cmovge esi,edi
     5:  39 d6                	cmp    esi,edx
     7:  0f 4c f2             	cmovl  esi,edx
     a:  39 ce                	cmp    esi,ecx
     c:  0f 4c f1             	cmovl  esi,ecx
     f:  89 f0                	mov    eax,esi
    11:  c3                   	ret

I will rename the code according to the calling convention used here.

    a -> edi
    b -> esi
    c -> edx
    d -> ecx

The result follows with some comments on what the code is doing.

    cmp    a,b
    cmovge b,a    # If a >= b, assign a to b.
                  # Now b has max(a, b).
    cmp    b,c
    cmovl  b,c    # If max(a, b) < c, assign c to b.
                  # Now b has max(max(a, b), c).
    cmp    b,d
    cmovl  b,d    # If max(max(a, b), c) < d, assign d to b.
                  # Now b has max(max(max(a, b), c), d).
    mov    eax,b  # Return b through eax.
    ret

I don't think it can be done in less code than this.

As one might expect, using C++ and std::max, we get almost identical x86.

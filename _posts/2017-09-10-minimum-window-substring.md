---
layout: post
title: Minimum Window Substring
---

# Description

This is a post regarding the solution to a substring problem which follows a
pattern that is quite common among substring problems: it is solvable with a
pair of fast and slow iterators.

If this is not possible, we will return the empty string.

## Problem Statement

Given two strings, S and T, find the minimum window in S which will contain all
the characters in T (with their frequencies) in linear time.

| S                   | T            | Answer   |
|---------------------|--------------|----------|
| `""`                | `""`         | `""`     |
| `""`                | `"A"`        | `""`     |
| `"A"`               | `""`         | `""`     |
| `"A"`               | `"A"`        | `"A"`    |
| `"A"`               | `"AB"`       | `"A"`    |
| `"ADOBECODEBANC"`   | `"ABC"`      | `"BANC"` |
| `"ADOBECODECABANC"` | `"ABC"`      | `"CAB"`  |

# C++ Solution

```cpp
{% include code/minimum-window-substring/snippet.cpp %}
```

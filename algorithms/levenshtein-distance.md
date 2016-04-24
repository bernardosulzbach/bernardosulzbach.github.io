---
layout: page
title: "Levenshtein distance"
---

Levenshtein distance is an edit distance that may be used to compare how
dissimilar two pieces of text are. For the Levenshtein distance, each addition,
deletion, or substitution add 1 to the total distance. When considering
Levenshtein distance, we are always interested on the smallest possible number
of transformations required to make a string into another. Therefore, "john"
and "jon" have a Levenshtein distance of 1, while "john" and "jose" have a
Levenshtein distance of 2 (and not 4, as some would suggest two deletions and
two additions).

Here is my implementation of Levenshtein distance using Python, just to show
how it can be done in a scenario on which you cannot depend on any libraries
other than the ones shipped with the language. Be aware that my implementation
has space-complexity and time-complexity O(m·n), where m and n are the size of
the input strings.

```python
def levenshtein(a, b):
    """
    Evaluates the Levenshtein distance between two strings.
    """
    if len(a) < len(b):
        a, b = b, a
    if len(b) == 0:  # len(a) >= len(b)
        return len(a)
    a = ' ' + a
    b = ' ' + b
    d = {}
    for i in range(len(a)):
        d[i, 0] = i
    for j in range(len(b)):
        d[0, j] = j
    for i in range(1, len(a)):
        for j in range(1, len(b)):
            if a[i] == b[j]:
                # Got the same character
                # Just use the answer to the prefix
                d[i, j] = d[i - 1, j - 1]
            else:
                # Not the same character
                # Use the smallest of diagonal, above or left
                # And add 1 to account for the extra modification needed
                d[i, j] = min(d[i - 1, j - 1], d[i, j - 1], d[i - 1, j]) + 1
    return d[len(a) - 1, len(b) - 1]
```

[The code in a Python source file]({{ site.baseurl }}/assets/levenshtein.py).

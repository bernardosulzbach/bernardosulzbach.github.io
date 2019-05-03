---
layout: page
title: "Number theory"
---

# Finding the number of digits of a factorial

If the argument is not too big, this can be tackled with logarithms.

See that the number of digits of `n!` is `ceil(log10(n!))` for `n` greater than
1.

By definition,

    n! = n * (n - 1) * ... * 1

Therefore,

    log(n!) = log(n) + log(n - 1) + ... + log(1)

Thus, a simple and fast solution in Python is:

```python
def factorial_digit_count(n):
    if n < 2:
        return 1
    return ceil(sum(log10(x) for x in range(1, n + 1)))
```

**Using 64-bit IEEE binary floating point, this function returns correct results
up to n = 3,121,515**.
This approximation evaluates to 18,916,606, rather than 18,916,607, which would
be the correct answer according to Wolfram Alpha and my PARI program.

See [the C++ program used to test this here]({{ site.baseurl }}/assets/algorithms/number-theory/factorial.cpp).

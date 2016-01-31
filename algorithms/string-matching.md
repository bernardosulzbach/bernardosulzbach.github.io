---
layout: page
title: String matching 
---

# Rabin-Karp (1987)

This algorithm speeds up equality testing by using a hash function.

If the hash of the substring from the text was recomputed at each iteration,
this would become an O(mn)-time algorithm, this problem is solved by reusing
the last computed hash in the evaluation of the new hash. Such a hash function
is called a **rolling hash**.

## Rabin Fingerprint

This hash treats every substring as a number in a base `a`, usually a large
prime.

    // A Rabin Fingerprint roll.
    hash -= first_char * a ^ (m - 1)
    hash *= a
    hash += new_last_char

This algorithm is slower than Knuth-Morris-Pratt and Boyer-Moore for single
pattern string searching because of its slow worst case behavior. However, it
is an algorithm of choice for multiple pattern search.

For instance, to find if any string of a large number of strings is in a text
we can create a variant of the Rabin-Karp algorithm that uses a set data
structure to check whether the hash of a substring belongs to a set of hash
values of patterns in constant time.

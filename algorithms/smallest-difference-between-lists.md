---
layout: page
title: Finding the smallest difference between lists
---

Input: two lists of numbers.

Objective: find the smallest difference between them (this is, the minimum value
that `mod(listA[i] - listB[j])` can take).

There are two simple ways to solve this problem and I will explain them here.
From now on, `m` is the size of `listA` and `n` is the size of `listB`.

The first one, and also the one that is easier to implement and to debug is to
simply compare each element from `listA` to each element from `listB`. This,
however simple, has O(m n) running time.

The second way to solve this problem, slightly more complicated, is to sort both
lists and iterate through them, advancing the iterator that points to the
smallest element (so that after an iteration the difference between the values
**may** be smaller). Modern programming languages tend to have quite good
implementations of at least one O(n lg n) sorting algorithm, so you are likely
not going to have to (re)write quicksort.

The sorting step has time complexity of O(m lg m) + O(n lg n) and the iteration's
worst-case time complexity is O(m + n). Making this substantially faster for
large enough `m` and `n`.

Here is a simple implementation of the second approach described above using C++
that I just finished.

```cpp
unsigned find_smallest_difference(const uvector& a, const uvector& b) {
    uvector::const_iterator it_a = a.begin();
    uvector::const_iterator it_b = b.begin();
    unsigned diff;
    unsigned smallest_difference = UINT_MAX;
    while (it_a != a.end() && it_b != b.end()) {
        diff = *it_a >= *it_b ? (*it_a - *it_b) : (*it_b - *it_a);
        if (diff < smallest_difference) {
            smallest_difference = diff;
        }
        // Increment the iterator that points to the smallest element.
        if (*it_a < *it_b) {
            ++it_a;
        }
        else if (*it_a > *it_b) {
            ++it_b;
        }
        else { // Found difference == 0, it is okay to break the loop.
            break;
        }
    }
    return smallest_difference;
}
```

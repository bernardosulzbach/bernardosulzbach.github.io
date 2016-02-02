---
layout: page
title: Reservoir sampling
---

Reservoir sampling is a family of randomized algorithms for randomly choosing a
sample of size **k** from a set **S** that contains **n** items, where **n** is
either very large or unknown. The answer for question 2-43 of the second edition
of The Algorithm Design Manual by Steve S. Skiena is a reservoir sampling
algorithm. The problem statement is as follows:

> You are given a set S of n numbers. You must pick a subset S' of k numbers
> from S such that the probability of each element of S occurring in S' is equal
> (i.e., each is selected with probability k/n). You may make only one pass over
> the numbers. What if n is unknown?

This is my implementation (using Python 3) of an algorithm that would solve this
problem in Θ(n) time.

```python
def random_sample(iterator, k):
  sample = []
  elements_so_far = 0
  for item in iterator:
    elements_so_far += 1
    if len(sample) < k:
      sample.append(item)
    else:
      index = int(random.random() * elements_so_far)
      if index < k:
        sample[index] = item
  return sample
```

# Sources

* Wikipedia
* The Algorithm Design Manual (2nd edition)

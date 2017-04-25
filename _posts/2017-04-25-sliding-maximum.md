---
layout: post
title: Sliding Maximum
---

In this post I will present a simple and somewhat generic solution for the
sliding maximum problem.

> Find the maximum element for every K consecutive elements.

Note that the sliding minimum can be seen as a negated sliding maximum problem,
just like the maximum spanning tree can be seen as the minimum spanning tree of
the negated graph.

# Implementation

Below is a generic C++ sliding window I implemented that takes a comparator as a
template parameter. This allows it to be instantiated for both the sliding
maximum and the sliding minimum.

```cpp
template <typename T, typename Comparator>
class SlidingWindow {
  struct Block {
    Block(T v, size_t w) : value(v), width(w) {}
    T value;
    size_t width;
  };
  Comparator comp;
  deque<Block> data;

 public:
  void push(const T t) {
    size_t width = 1;
    while (!data.empty() && comp(data.back().value, t)) {
      data.pop_back();
      width++;
    }
    data.emplace_back(t, width);
  }
  T get() const { return data.front().value; }
  void pop() {
    // Either reduce the width of the best block (front), or drop it.
    if (data.empty()) {
      return;
    }
    if (data.front().width > 1) {
      data.front().width--;
    } else {
      data.pop_front();
    }
  }
};
```

This solution is amortized O(1) for all operations, making it O(N) for N
elements. By using STL trees we cannot do better than O(N log N).

# Example

Using 20 terms and a window of width 4, we have the following table:

| Current | Maximum | Minimum |
|---------|---------|---------|
|      16 |      16 |      16 |
|       1 |      16 |       1 |
|       2 |      16 |       1 |
|      13 |      16 |       1 |
|       9 |      13 |       1 |
|      11 |      13 |       2 |
|      15 |      15 |       9 |
|      14 |      15 |       9 |
|       4 |      14 |       4 |
|       8 |       8 |       4 |
|       3 |       8 |       3 |
|       7 |       7 |       3 |
|       6 |       7 |       3 |
|      12 |      12 |       6 |
|       5 |      12 |       5 |
|      18 |      18 |       5 |
|      19 |      19 |       5 |
|      17 |      19 |      17 |
|      20 |      20 |      17 |
|      10 |      20 |      10 |

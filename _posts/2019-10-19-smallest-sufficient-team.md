---
layout: post
title: Solution to Smallest Sufficient Team
---

This is my solution for the LeetCode problem number 1125, [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/).

This problem is a version of a well-known NP-complete problem in computer science known as the [set cover problem](https://en.wikipedia.org/wiki/Set_cover_problem).
In order to make the solution fast enough to pass the time limit, redundant people are removed from the set of candidates.
If $$s_i$$ denotes the set of skills of person $$i$$ and $$s_i \cup s_j = s_i$$, person $$j$$ is redundant, as it does not do anything more than $$i$$ can and therefore is not required to find an optimal solution.

Another possible optimization would be to determine if there are any required people. Where a required person would be one that possesses a skill no other person does.
This person simply has to be part of the solution and can be removed from the search and added to the solution unconditionally.

The required skills and each person's skills are represented by 16-bit unsigned integers, because computing their union is much faster than computing the union of vectors of strings.
After this, it basically becomes a matter of considering each person and exhaustively testing all of the possible solutions.
Sorting the vector of people from "most skilled" to "least skilled" may also speed up the search considerably.
Lastly, the search can stop whenever the current solution being built gets to be as large as the best one found so far.

[The C++ implementation can be found here]({{ site.baseurl }}/assets/smallest-sufficient-team/main.cpp).


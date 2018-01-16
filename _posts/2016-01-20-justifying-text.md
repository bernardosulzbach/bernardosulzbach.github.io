---
layout: post
title: "Justifying Text"
---

In this post I briefly describe how good text justification is done using
dynamic programming. In the future, I may post code for this problem.

Start by writing a 'badness' function that produces a value corresponding to
how bad it is to have a certain set of words forming a line.

LaTeX uses the following formula for badness

    badness(i, j) = (page_width - total_width)³    if [i, j] fits
                    ∞                              otherwise

    where
      i is the index of the first word of the line
      j is the index of the last word of the line
      page_width is the width of the document page
      total_width is the width occupied by the letters of the words [i, j]

Then, by using dynamic programming techniques, you need to find the line
combination that gives the minimum badness sum.

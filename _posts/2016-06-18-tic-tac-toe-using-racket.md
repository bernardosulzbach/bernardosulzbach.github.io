---
layout: post
title: "Solving Tic-Tac-Toe Using Racket"
---

I decided to implement a perfect AI (using
[Minimax](https://en.wikipedia.org/wiki/Minimax)) for 
Tic-tac-toe. I had not decided though whether I'd use JavaScript or Racket,
two languages I've been using quite a bit recently and about which I am quite
interested. As the post title gives off, I've decided to write a functional
programming solution using Racket. It is open-source and available on GitHub.
[See the repository](https://github.com/mafagafogigante/tic-tac-toe). There is
also a fairly decent GUI-based game that allows you to play against the AI.

![GUI-based Tic-tac-toe game]({{ site.baseurl }}/assets/tic-tac-toe.png)

When writing this I decided to use
[vectors](https://docs.racket-lang.org/reference/vectors.html) instead of
[lists](https://docs.racket-lang.org/reference/pairs.html), expecting it would
give me better performance. However, it is quite slow. Even though the current
implementation is good enough for real-time gameplay, it could be much more
efficient for such a simple decision tree as the one used in Tic-tac-toe. Maybe
using lists would have been a better choice as some parts of the application now
have to convert vectors to lists. Additionally, slicing and merging vectors seem
to generate a lot of work for the garbage collector. Finally, as the biggest
vector holds only nine elements, the constant-time random access vectors provide
is likely not making too much of a difference.

Being an automation enthusiast myself. This project also got its amount of
continuous integration and delivery. Every push and pull request is built and
tested by Travis CI. [Here you can find the build history of the
project](https://travis-ci.org/mafagafogigante/tic-tac-toe). Travis also
prepares and deploys a Linux-only standalone distribution to GitHub releases on
tags. [See the releases
page](https://github.com/mafagafogigante/tic-tac-toe/releases). In the future I
may make Windows and Mac OS X standalone distributions available. You should be
able to play the standalone game on Linux even without having Racket installed.

There is also [alpha-beta
pruning](https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning) left to be
implemented, which should also significantly improve performance. Even though
this is still a work in progress, the game works and the AI is indeed perfect.
It also runs in any operating system as long as it has a [Racket
6](https://racket-lang.org/) distribution installed.

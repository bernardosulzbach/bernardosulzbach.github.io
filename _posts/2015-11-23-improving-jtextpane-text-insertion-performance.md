---
layout: post
title: Improving JTextPane text insertion performance
---

After I started benchmarking how much time commands took to complete in
Dungeon, I noticed that writing a full world map (a grid of colored ASCII
characters) to the screen was reasonably slow. Then I set forth to find the
solution to my problem.

Basically, there are two causes for slow `JTextPane` updates: each insertion
triggers a re-rendering of the display and some methods in the
`DefaultStyledDocument` class are synchronized, so there is the overhead of
acquiring locks.

I worked on the first issue and was able to reduce the overhead of insertion
substantially. I wrote a class that keeps two `StyledDocuments`: one inactive
and one set to the `JTextPane` the class is responsible for. When text is
written to this object, it will update the `StyledDocument` that is inactive,
swap both documents, and then update the now inactive `StyledDocument`. Why
keep two documents?  Some insertions are just small increments, that really
benefit from not having to rewrite a long passage of text multiple times.

How to make it faster? Instead of running the second document update (the user
has already seen the update one because the swap has already taken place) on
the same thread, delegate it to a worker thread. Note that this approach will
block this object for a while. To keep it simple and avoid premature
optimization, I did not even code this multithreaded version. But I am
mentioning it here just in case someone (maybe me) needs it in the future.

For reference, [the issue related to the
post](https://github.com/mafagafogigante/dungeon/issues/176).

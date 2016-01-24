---
layout: post
title: License notes should have a date
---

When working on [dungeon](https://github.com/mafagafogigante/dungeon/) license
notes I came to notice that we are in 2016 and this means that all files that I
change right now require their license notes to be updated.

I wondered if I actually needed that, so I went to [Programmers Stack
Exchange](https://programmers.stackexchange.com/) and [asked about
it](https://programmers.stackexchange.com/questions/307934/using-a-license-without-a-year-value).
I got quite helpful answers and comments within a few hours. Essentially, it
boils down to

1. Copyright expires, therefore you must provide a license date.
2. The format `Copyright (C) [years] [name]` should not be changed.

Therefore, I must set up Git Hooks that will update all license notes of the
files with a list of years in which the file has been modified.

The solution will likely be open-sourced so it benefits a bigger group of
people.

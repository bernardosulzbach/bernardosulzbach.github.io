---
layout: post
title: Dungeon Is Now Using Checkstyle
---

Dungeon has had a
[style guide](https://github.com/mafagafogigante/dungeon/blob/master/STYLE.md)
for some time now. However, it was not enforced by anything other than
human reading. Even if my IDEA settings were very compliant – and I
followed them scrupulously –, I got nothing more than warnings.

In search of higher code quality, I decided to start using Checkstyle. I
cannot use its latest version as it requires Java 7, and I want Dungeon
to be compatible Java 6. The worst part is that the CustomImportOrder
module only checks import sorting according to ASCII order instead of
case-insensitive alphabetical order after version 6.5. Unfortunately, as
I am using Checkstyle 6.2, I have no choice but to disable the
aforementioned rule.

Not only I discovered Dungeon had about one hundred Checkstyle
violations, Checkstyle made me write some important Javadoc for public
methods whose purpose was not obvious to me.

Why does this matter? It is common sense that standardization of source
code increases its readability and makes it substantially easier to spot
problems.

Dungeon source quality is increasing, and seeing this happening is
pretty fulfilling. I think I will try to introduce other checkers in the
future, maybe FindBugs and a spell checker. In the end, typos in a
text-based game are the equivalent of visual glitches in games that rely
heavily on graphics.

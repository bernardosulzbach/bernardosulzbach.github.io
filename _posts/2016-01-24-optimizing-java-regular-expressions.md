---
layout: post
title: Optimizing Java Regular Expressions
---

I have been working with regular expressions a lot lately and thought I should
share some ideas on how to make regular expressions faster in Java. Most of this
ideas are quite simple yet may give you very good improvements in practice.

# Low hanging fruits
Compile `Pattern`s you use frequently.

Use small capture groups to prevent long backtracking.

Whenever possible, use non-capturing groups. `(?:P)` instead of `(P)`.

# Reluctant, greedy, and possessive quantifiers
Usually, reluctant quantifiers will run faster than greedy quantifiers. I am
talking about `+?` and `*?` being faster than `+` and `*`. When the engine finds
a greedy quantifier, it will go for the biggest possible match and start
backtracking. In big strings this is usually extremely slow if you are trying to
match a small substring (which is often the case), so going for reluctant
quantifiers - that "grow" the match - instead of greedy ones - that "shrink" the
substring they are trying to match - is very likely to improve performance.

Possessive quantifiers improve regular expression performance a lot. Therefore,
you should use them whenver you can. `P?+`, `P*+`, `P++` will match the pattern
as any greedy quantifier would, but will never backtrack once the pattern has
been matched, even if refusing to do so means that whole expression will not
match.

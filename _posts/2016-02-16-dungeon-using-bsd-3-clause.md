---
layout: post
title: "Dungeon is Using the BSD 3-Clause License"
---

Last weekend I was determined to solve [Dungeon's licensing issues]({{ site.url
}}/license-notes-should-have-a-date/). However, after seeing how much work
figuring out in which year each file was modified from Git history would be, I
decided to take a simpler route that I believe will make Dungeon an even better
project. I changed to the BSD 3-Clause license, which seems to accept having a
single license notice for the whole project. Thus, individual files no longer
need their own preambles.

From the [GNU
website](https://www.gnu.org/licenses/gpl-faq.en.html#NoticeInSourceFile):

> You should put a notice at the start of each source file, stating what
> license it carries, in order to avoid risk of the code's getting disconnected
> from its license.

Which is a good point. However, it does not really apply to Dungeon. **Most of
the code is very project-specific and wouldn't be of much use elsewhere**.
Also, if you want to copy a generic solution, such as our `CircularList` and
never give back, I am OK with it and hope you make good use of my code.

The mentioned page also states that

> This has nothing to do with the specifics of the GNU GPL. It is true for any
> free license.

As I said, I don't have enough reasons to do this as I am already using a
permissive license. One could argue that the no warranty clause should always
be present, but I don't think it is an important issue right now, as to make me
responsible for damage caused by my software would require acknowledging that
the code came from the repository, which has a license note of the BSD 3-Clause
license.

I've come to like permissive licenses a lot more in the last two years. I think
that the most open and free the code is, the more value it has as more people
may benefit from it. And this may be more easily achieved by using permissive
(non copyleft) licenses, such as the BSD licenses.

In the end, I just hope this is for the best of my species and that everyone
can benefit, or, at least, not be damaged by the license change.

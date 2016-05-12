---
layout: post
title: The Difference Between 1080p And 1080i
---

A few days ago I found myself talking to a colleague about the differences
between 1080p and 1080i. Inspired by that conversation, I have decided to write
about these differences.

Note beforehand that both these resolutions have 1080 horizontal lines.
1080**p** is a **frame-based** (or **progressive**-scan) video where the frame
rate is expressed in terms of **frames** per second. 1080**i** is a **field-
based** (or **interlaced**-scan) video whose frame rate is expressed in terms of
**fields** per second. In this context, a _**field**_ is _either all the odd
lines of a frame or all its even lines_.

1080p most common frame rates are 24, 25, and 29.97 _frames_ per second while
1080i most common field rates are 50 and 59.94 _fields_ per second. 1080p at 25
frames per second would correspond to 25 full bitmaps of 1920 x 1080 pixels.
1080i at 50 fields per second, on the other hand, represent 50 bitmaps of 1920 x
540 pixels - as if you were shooting 50 pictures per second but storing only
half of the bitmaps every time – sometimes you store the odd lines and sometimes
the even lines.

There is a lot of difference between 25 full pictures and 50 halves, although
common sense may tell you otherwise. These 50 halves are not simply 25 pictures
divided in half, but _**50 different pictures**_ with half of their content
thrown away. Interlacing make mundane operations on frames such as video scaling
and rotating, video pausing, screenshot capturing, and reverse playback quite
complicated. Video encoding is also more complicated for interlaced video
because the codec does not work with full frames.

The biggest downside of 1080p is its substantially lower frame rate, but the
deinterlacing problems that may arise from 1080i resolution generally make it a
worse choice. Although most TV transmissions are interlaced, **plasma and LCD
screens are progressively scanned**, making a process known as deinterlacing
necessary. Bad deinterlacing - likely to occur in very fast-paced scenes - may
produce undesired effects such as the one demonstrate by the image below.

![Bad deinterlacing]({{ site.baseurl }}/assets/interlaced_video_frame.jpg)

At the end, which combination of frame resolution and scan type you use is a
choice that depends on how much you can spend and which options are available.
However, _**I don't see any reason to opt for 1080i over 1080p if you can freely
pick between them**_.

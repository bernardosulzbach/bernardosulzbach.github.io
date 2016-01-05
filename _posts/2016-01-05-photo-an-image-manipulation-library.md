---
layout: post
title: Photo: an image manipulation library
---

This is an announcement of a Java image manipulation library I created.

It is released under BSD 2-Clause and can be found here. The main reason for
creating it was that there was not an open source Directional Cubic Convolution
Interpolation implementation out there in Java.

According to Wikipedia,

> [An article]({{ site.url }}/assets/performance-evaluation-of-edge-directed-interpolation.pdf)
> from 2013 compared the four algorithms above, and found that DCCI had the
> best scores in PSNR and SSIM on a series of test images.

There is also a dedicated page for this library [here]({{ site.url }}/photo/).

A Maven artifact is on its way. If you have any suggestions or requests, send
me an email or create a new issue.

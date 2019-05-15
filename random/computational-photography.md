---
layout: page
title: Computational photography
tags: [random]
---

# Digital cameras

Even though optical systems can be very complex, the fundamental ideas can be
understood from studying the simplest optical system, which is the thin lens.
It has an optical axis passing through the lens center and two focal points
placed on opposite sides of the optical axis and equidistant from the lens
center.

Any ray entering the lens parallel to the optical axis on one side goes through
the focal point on the other side. Similarly, any ray entering the lens from
the focal point on one side emerges parallel to optical the axis on the other
side.

## The thin lens equation

1 / f = 1 / d<sub>o</sub> + 1 / d<sub>i</sub>

## Snell's law

η<sub>1</sub> sin θ<sub>1</sub> = η<sub>2</sub> sin θ<sub>2</sub>

## Capturing color

Because the photodiodes that make up the sensor are monochrome devices, we need
to use color filters. Then we can use three CCDs (one for each of red, green,
and blue) or one CCD with a color filter array (CFA), such as the Bayer
pattern.

## Gamma encoding

Because the human visual system is more sensitive to variations in darker
shades, gamma compression is performed. It reserves more bits to darker shades.

## Issues

Blooming is caused when the photodiodes overflow and contaminate adjacent
pixels. A solution is the create overflow wells, but this takes precious sensor
area.

# Time of flight cameras

These cameras send light into the scene and measure how it reflects back to it.
Needless to say, they have to sample light in very short time intervals. Using
a time counter is not easy as it would require very high frequencies. A better
solution is to use phase shift to compute how long the light took to get back
to the camera.

Even though flight cameras can work at higher frame rates than many consumer
grade cameras, they do not have great resolution.

# Infrared cameras

These are also called thermographic cameras. They filter out higher frequencies
(such as frequencies in the visible spectrum) in order to measure how hot
surfaces are and useful to detect animals, perform heat-loss detection, and
analyze heat dissipation.

# Fourier transforms

There are four Fourier representations.

They map discrete (space) into periodic (time), and continuous (space) into
non-periodic (time). The inverses are also true.

That means that a discrete and non-periodic signal will be transformed into
continuous and periodic by the Fourier transform.

A non-periodic function can be sen as the limiting case of a periodic one, with
its period approaching infinity. It's fundamental frequency tends to zero.
Therefore, we need all frequencies to represent this function.

Only the discrete Fourier transform (DFT) and its inverse can be evaluated
exactly in a digital computer.

The DFT by itself cannot prevent aliasing. It is during sampling that whether
or not there will be aliasing is determined. Sampling happens before the
application of the DFT.

The DFT and its inverse always exist.

One can use the DFT to analyze 2D signals (such as images). It is worth
pointing out that the inverse might produce imaginary values due to rounding
errors.

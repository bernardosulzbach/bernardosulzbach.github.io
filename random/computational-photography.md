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

# Color

A color model is a mathematical model describing the way colors can be
represented as tuples of numbers, such as triples in RGB or quadruples in CMYK.
A color space is a specific organization of colors which allows for
reproducible representations of color. It is a particular combination of a
color model and a mapping function.

# Dynamic range

The human vision has greater dynamic range than most cameras. One thing that
can be done to get images that capture a wider dynamic range is to use multiple
low dynamic range pictures, combine their radiance values into a high dynamic
range image and use a tone mapping operator in order to get a low dynamic range
image which contains now more details.

Irradiance can be approximated from pixel values by undoing the gamma
transformation, then using the inverse of the camera response curve (a curve
which stores - per color channel - the amount of incoming light required to get
a certain pixel value) and finally dividing the results by the exposure time.

There are global and local tone mapping algorithms. While global tone mapping
algorithms use the same parameters to process all pixels in the image, local
tone mapping algorithms might use different parameters depending on the
neighboring pixels.

There are displays with higher dynamic range than most consumer screens.

# EXIF metadata

EXIF, or exchangeable image file format, metadata stores information about the
camera and the settings used to take the picture.

# Vector differential operators

The ∇, or nabla, or is a vector differential operator which takes derivatives
of the quantity on which it was applied to.

The gradient is the result of the application of ∇ to a scalar field in order
to produce a vector field.

The divergent produces a scalar field from a vector field. It is positive if
the vectors it are diverging.

The curl produces a vector field from a vector field. It indicates the tendency
of a vector field to circulate around a point.

The Laplacian is the concatenation of the gradient and the divergent. It works
as a concavity and peak detector. It is positive on minima and negative on
maxima.

# Image compositing

Seamless cloning is a technique which uses the Laplacian operator before
solving a minimization problem on the difference of the gradient fields of the
original image and the cloned region. It's based on the fact that humans notice
large variations much more easily than small continuous differences.

# Image segmentation

The intelligent scissors method uses information about the gradient of the
image to find path between two control points which crosses the minimum number
of edges.

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

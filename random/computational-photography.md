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

# Image restoration

If f(x, y) is an image, letting h(x, y) be a degradation function and n(x, y)
be a noise function, then g(x, y) = f(x, y) ∗ h(x, y) + n(x, y) is a possible
way to model a degraded version of f(x, y). Image restoration techniques may
attempt to obtain f(x, y) from g(x, y).

Even if H(u, v) (the DFT of h(x, y)) is known, recovering F(u, v) may be
impossible as N(u, v) is random.

F'(u, v) = F(u, v) + N(u, v) / H(u, v)

If H(u, v) has small values, it may drastically affect the values of F'(u, v)
during reverse filtering. This means that **inverse filtering is very sensitive
to noise**.

## Wiener filter

The [Wiener filter](https://en.wikipedia.org/wiki/Wiener_filter) is a type of
filter that attempts to minimize the impact of noise. It minimizes the mean
square error between the estimated random process and the desired process.

In case there is no noise, it reduces to inverse filtering.

When N(u, v) and F(u, v) are not known and cannot be estimated, an
empirically-chosen constant K is used.

# Coded aperture

A conventional aperture is a **depth-dependent low-pass filter**. Because the
circles of confusion increase with the distance from the point to the focal
plane, depth can be estimated based on the size of the blur kernel.

Factorable masks are masks defined as the convolution of a structural component
(S) and a hole component (h). S defines the location and the transparency of
the mask's holes and h improves the mask's light efficiency. These masks
generate superimposed image copies, which can then be solved to recover both
color and depth from single images based on mask factorization.

Factorization has several advantages, such as simplifying analysis, design,
implementation, and deconvolution compared to previous approaches are based on
optimization.

For more details, the following paper is a relevant source. [Fortunato, H. E.
and Oliveira, M. M. (2012), Coding Depth through Mask Structure. Computer
Graphics Forum, 31: 459-468](https://doi.org/10.1111/j.1467-8659.2012.03025.x).

# Deconvolution

Image capture might be modelled as the following convolution.

    g = h ∗ f + n

Deconvolution to obtain f from g is a highly ill-posed problem, whose solution
requires additional constraints.

This type of deconvolution has several applications in microscopy, photography,
and astronomy.

Deconvolution is said to be blind when the impulse response function used in
the convolution is not known and non-blind when it is known.

Padding can prevent ringing artifacts at the borders when performing frequency
domain deconvolution.

# Edge-aware image processing

Color images can be seen as a 2-D surface embedded in a 5-D space.

An edge-preserving filter can be described as a 5-D spatially-invariant
convolution kernel whose response decreases as distances among pixels increase
in 5-D.

Convolution in 5-D is usually too slow to be done directly. However, by
preserving the distances observed in the 5-D space in a lower-dimensional
space, edge-aware filtering can be done more efficiently.

There is a domain transform that preserves geodesic distances on 1-D image
manifolds embedded in n-D space. It is show in [Eduardo S. L. Gastal and Manuel
M. Oliveira. "Domain Transform for Edge-Aware Image and Video Processing". ACM
Transactions on Graphics. Volume 30 (2011), Number 4, Proceedings of SIGGRAPH
2011, Article 69](https://doi.acm.org/10.1145/1964921.1964964).

The domain transform scales the signal by a function of its range, in such a
way that, by applying a local scaling to each position, a linear filter can
work as an n-D filter.

A 2-D domain transform cannot exist in general because it would require mapping
a 2-D manifold in n-D to R<sup>2</sup>.

The proposed 1-D transform can be used to perform high-quality edge-preserving
2-D filtering by iterating 1-D filtering operations.

In order to perform 2-D filtering through the 1-D filter, a few iterations are
required. Horizontal and vertical passes are interleaved and the length of the
filter support is halved at each iteration.

There are three main filter realizations for doing domain transform filtering.

**Normalized convolution**. Good for stylization and abstraction: smooths
similar regions and sharpens relevant edges.

**Interpolated convolution**. Good for applications where edge sharpening is
not desirable, such as tone mapping, detail manipulation.

**Recursive filtering**. Good for edge-aware interpolation, such as
colorization and recoloring. It propagates information across the whole image.

## Filter separability

A separable filter in the context of image processing can be written as product
of two more simple filters. A typical example is a 2-dimensional convolution
operation separated into two 1-dimensional filters, which reduces the cost of
computing the operator.

# Adaptive manifolds

One can sample the high-dimensional space at a few points and use this
information to interpolate the filter response for all pixels. An important
observation is that one can improve filtering performance if the sampling
points are on a small number of manifolds adapted to the signal.

There is a technique for high-dimensional filtering with linear cost in the
number of pixels and in the dimensionality of the space proposed in [Eduardo S.
L. Gastal and Manuel M. Oliveira. "Adaptive Manifolds for Real-Time
High-Dimensional Filtering". ACM Transactions on Graphics. Volume 31 (2012),
Number 4, Proceedings of SIGGRAPH 2012, Article
33](https://doi.acm.org/10.1145/2185520.2185529).

Through this technique one can perform filtering in high-dimensional spaces by
creating adaptive manifolds, projecting the signal onto these manifolds, then
filtering these projections, and at last integrating them together.

# Image forensics

## Acquisition traces

The use of color filter arrays (CFAs) introduces demosaicing traces
(correlation between neighbor pixels). Modifications might also change sensor
noise patterns.

## Compression traces

There are compression traces, which can indicate that an image has been
compressed twice.

## Editing traces

Editing traces are lighting traces and geometric traces.

## Lack of standardization

Image forensics lacks terminology standardization as of 2015.

# Filtering of non-uniformly sample signals

Some applications are better defined using non-uniform sampling. Through
High-order recursive filters, one can obtain practically unlimited control over
the filtering kernel.

Recursive filters have several advantages, such as the linear time complexity
on the number of samples, their infinite impulse response (IIR), and their
straightforward implementation. With recursive filters it is possible to
approximate many important filters.

High-order filters can be decomposed into first-order filters through
partial-fraction expansion. By applying all first-order filters in parallel and
accumulating the results one can obtain the final filtered signal.

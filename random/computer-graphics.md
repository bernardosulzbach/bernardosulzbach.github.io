---
layout: page
title: Computer graphics
tags: [random]
---

# Texture mapping

## Bilinear filtering

Bilinear filtering provides good results if the objects are close to the
camera. However, it does not work well when the object is far away and multiple
texels map to the same pixel. For distant objects it would be necessary to
average all the contributing texels, which has to be precomputed, for instance,
by using image pyramids.

## Perspective correct interpolation

Pixel space is related to 3-D homogeneous space through a linear matrix
multiplication. Consequently, the linear interpolation of pixel space
coordinates is related to the linear interpolation of 3-D homogeneous space
coordinates.

1. Construct an array of values for each vertex of the polygon after
multiplication by the projection matrix, including an 1 at the end.
2. Perform clipping.
3. Perform the perspective division to all elements of the vector (divide by by
W). The last term becomes 1/W.
4. "Interpolate all values linearly down polygon edges and across scanlines
internal to the polygon".
5. At each pixel, divide the resulting values by the interpolated 1/W.

# Visible surface determination

## Painter's algorithm

Primitives are sorted by Z coordinate in camera space and rendered from back to
front. Interpenetrating polygons need to be split. Can be sped up by BSP trees.

## Visible surface ray tracing

Traces rays through each pixel of the image plane and find the closest
intersection with the objects in the scene.

## Depth buffering

Keeps track of the current depth associated with each pixel. These values are
interpolated during rasterization. Can be done through a Z-buffer or a
W-buffer.

### Z-buffer

Perspective-correct interpolation of Z values provides more precision near the
camera (using linearly-interpolated Z values results in uniform precision). The
resolution of a Z-buffer depends on the ratio Z<sub>far</sub> /
Z<sub>near</sub>.

### W-buffer

W is defined in terms of the Z coordinate in camera space and therefore its
value is independent of Z<sub>near</sub>. W-buffer is the best choice if one
needs to make Z<sub>near</sub> very small.

# Quaternions

Quaternions are the 3-D analogues for complex numbers and rotations in 2-D.

A quaternion is defined as the following sum.

q = q<sub>0</sub> + <b>q</b> = q<sub>0</sub> + <b>i</b>q<sub>1</sub> +
<b>j</b>q<sub>2</sub> + <b>k</b>q<sub>3</sub>

Therefore, a quaternion can be represented by a 4-tuple of real numbers.

Quaternions observe some special products

<b>i</b><sup>2</sup> = <b>j</b><sup>2</sup> = <b>k</b><sup>2</sup> = <b>ijk</b>
= -1

<b>ij</b> = <b>k</b> = -<b>ji</b>

<b>jk</b> = <b>i</b> = -<b>kj</b>

<b>ki</b> = <b>j</b> = -<b>ik</b>

After grouping the intermediate results of the multiplication of two
quaternions p and q, we get the following formula.

pq = p<sub>0</sub>q<sub>0</sub> - <b>p</b>·<b>q</b> + p<sub>0</sub><b>q</b> +
q<sub>0</sub><b>p</b> + <b>p</b>×<b>q</b>

Where p<sub>0</sub>q<sub>0</sub> - <b>p</b>·<b>q</b> is a scalar and
p<sub>0</sub><b>q</b> + q<sub>0</sub><b>p</b> + <b>p</b>×<b>q</b> is a vector.

The complex conjugate q\* of q is given by q\* = q<sub>0</sub> - <b>q</b>.

The norm of a quaternion $$q$$, denoted by $$\|q\|$$ is $$\sqrt{q q^{*}}$$.

The norm of a product is the product of the norms, $$\|pq\| = \|p\|\|q\|$$.

Every non-zero quaternion q has a multiplicative inverse $$q^{-1}$$, such that
$$q^{-1}q = qq^{-1} = 1$$.

A closed formula for the inverse can be found as following.

$$
\begin{align*}
              & q^{-1}qq^{*} = q^{-1} \|q\|^{2} = q^{*} \\\\
\therefore {} & q^{-1} = \frac{q^{*}}{\|q\|^{2}}
\end{align*}
$$

A rotation in R<sup>3</sup> can be represented by a 3x3 orthogonal matrix with
determinant 1. This matrix is a rotation operator in R<sup>3</sup>. Quaternions
are an alternative form of the rotation operator in R<sup>3</sup>.

Quaternions (which are in R<sup>4</sup>) can operate in vectors from
R<sup>3</sup> by considering all vectors in R<sup>3</sup> pure quaternions,
that is, quaternions whose scalar part is zero.

Rotating $$v$$ around $$q$$ is performed by $$qvq^{*}$$. This is guaranteed to
be a pure quaternion.

# Shadows

Shadows are regions of a scene not completely visible by the light sources.
They are one of the most important clues about the spatial relationship among
objects in a scene.

Most common shadow algorithms are restricted to direct light and point or
directional light sources. Area light sources are usually approximated by
several point lights.

The terms _umbra_ and _penumbra_ are used to mean complete shadow and partial
shadow, respectively.

## Planar shadows

Works by projecting the polygonal models onto a plane and painting this
projection as a shadow.

## Shadow mapping

Shadow mapping is an image-based algorithm which uses a depth buffer. It can be
applied to any surface that can be rasterized. It is usually implemented in
graphics hardware by using the texture sub-system.

It works by generating a depth map (shadow map) of the scene from the point of
view of each light source.

Each fragment which is visible to the camera needs to be mapped to the light
space of each light source too in order to check whether or not they were
reached by the light source or not.

Shadow mapping is prone to aliasing (both during the construction and during
access) and self-shadowing (which requires a bias factor to be used when
testing).

The expression for obtaining the texture coordinates for a vertex of an object
is the following.

$$(SP_{L}LM)X_{O}$$

## Percentage closer filtering

In this method, the shadow test is performed against an area of the shadow map.

## Volumetric shadows

For each light source, shadow polygons are created. Then, starting with a
counter set to the number of shadow volumes containing the eye, rays are traced
from the eye towards the target. We add 1 for each front facing shadow polygon
and subtract 1 for each back facing shadow polygon. Then, if the counter is
zero, the object is lit, if the counter is greater than zero, the object is in
shadow.

## Radiosity

Shadows are determined by the form factors among the elements of the scene.

## Ray tracing

Trace rays from the surface point to each light sources and check if there are
any intersections.

## Light map

Light maps are data structures used to store the brightness of surfaces in a
virtual scene. It is pre-calculated and stored in texture maps for later use.
They are used to provide good quality global illumination at a relatively low
computational cost.


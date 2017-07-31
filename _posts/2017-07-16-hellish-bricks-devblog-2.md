---
layout: post
title: Hellish Bricks DevBlog 2
---

This is an update on what I have recently done to Hellish Bricks.

# Progression Curves

The game got progression curves for running speed and initial jump speed.

![Speed Curve]({{ site.baseurl }}/assets/hellish-bricks/devblog-2/speed.svg)

![Jump Speed Curve]({{ site.baseurl }}/assets/hellish-bricks/devblog-2/jump-speed.svg)

These are important so that the character evolves, creating more gameplay
possibilities as the game progresses.

# Colored Lights

I've also enabled lantern and ambient light commands so that the player can
change the lantern and the ambient light colors during the game or during
initialization, through the boot script.

## Default Boot Script

```
# Set lantern to a light yellow.
lantern #EEEEBB
# Set ambient to a dark red.
ambient #443322
```

## White and Colored Lights Comparison

![White Lights]({{ site.baseurl }}/assets/hellish-bricks/devblog-2/white-lights.png)

![Colored Lights]({{ site.baseurl }}/assets/hellish-bricks/devblog-2/colored-lights.png)

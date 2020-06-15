---
layout: page
title: Portfolio
tags: [sidebar]
---

This is a non-exhaustive list of projects I developed.

## Dungeon

Dungeon is a text-based open-world Java role-playing game.

In 2017, Dungeon won a $1024 software quality award.

### Screenshots

![The new game screen]({{ site.baseurl }}/assets/new-game.png)
![The map]({{ site.baseurl }}/assets/map.png)

See [the GitHub repository](https://github.com/bernardosulzbach/dungeon/), [the project page]({{ site.baseurl }}/dungeon/).

## Walls of Doom

A platformer in C, rewritten in modern C++.

See [the GitHub repository](https://github.com/walls-of-doom/walls-of-doom/), [the website](https://walls-of-doom.github.io/).

## Better Chest Organizer 

Better Chest Organizer is a mod for [Stardew Valley](https://www.stardewvalley.net/) written in C#.
The default in-game chest organization functionality is very incomplete, often not using enough criteria when determining the chest item order.
To make matters worse, the default implementation does not use a stable sorting algorithm.
This mod provides better automatic chest organization, fixing these problems.

### Examples

#### Example 1

<p align="center">
  <img src="https://github.com/bernardosulzbach/BetterChestOrganizer/raw/master/images/example-1-1.png"
       alt="A chest with artisan products after sorting by the in-game button">
  <figcaption>A chest with artisan products after sorting by the in-game button. The jellies (red jars) are mixed with the other product types.</figcaption>
</p>

<p align="center">
  <img src="https://github.com/bernardosulzbach/BetterChestOrganizer/raw/master/images/example-1-2.png"
       alt="A chest with artisan products after sorting by the mod">
   <figcaption>A chest with artisan products after sorting by the mod. Different product types are clustered together.</figcaption>
</p>

#### Example 2

<p align="center">
  <img src="https://github.com/bernardosulzbach/BetterChestOrganizer/raw/master/images/example-2-1.png"
       alt="A chest with mushrooms of varying quality after sorting by the in-game button">
  <figcaption>A chest with mushrooms of varying quality after sorting by the in-game button. The mushrooms are sorted by their variety, but their quality has not been taken into account.</figcaption>
</p>

<p align="center">
  <img src="https://github.com/bernardosulzbach/BetterChestOrganizer/raw/master/images/example-2-2.png"
       alt="A chest with mushrooms of varying quality after sorting by the mod">
  <figcaption>A chest with mushrooms of varying quality after sorting by the mod. The mushrooms are sorted by their variety and then by their quality.</figcaption>
</p>

See [the GitHub repository](https://github.com/bernardosulzbach/BetterChestOrganizer).

## BigWord

An application to efficiently find words in a dictionary from a multiset of letters.
This is, the application finds the largest possible words from a bag of available characters.

### Examples

```bash
$ ./bigword linkedlists
> instilled
> kindliest
> niellists
> slinkiest

$ ./bigword abcdefghij
> bighead
> jibhead

$ ./bigword aeioubsdlinux
> unoxidisable
```

### Design

Data is serialized after processing in order to speed up subsequent runs.

### Performance

On average, the application can query against a dictionary of 500,000 words in around 50 milliseconds.

See [the GitHub repository](https://github.com/bernardosulzbach/bigword).

## Contagium

A JavaScript game.

See [the GitHub repository](https://github.com/contagium/contagium/), [the website](http://contagium.github.io/).

## Photo

A Java image manipulation library.

See [the GitHub repository](https://github.com/bernardosulzbach/photo/), [the project page]({{ site.baseurl }}/photo/).

## Notes

My public LaTeX notebook.

See [the GitHub repository](https://github.com/bernardosulzbach/notes/), [the last release](https://github.com/bernardosulzbach/notes/releases/latest/), [the issue tracker](https://github.com/bernardosulzbach/notes/issues/).

## See also

You may also be interested on my [list of open-source contributions]({{ site.baseurl }}/open-source/).
I believe that giving back is fundamental to keep the software development ecosystem healthy.

---
layout: page
title: Portfolio
tags: [sidebar]
---

This is a non-exhaustive list of projects I have developed on my own.

## BigWord

An application to efficiently find words in a dictionary that can be formed from a user-provided multiset of letters.
Think of it as forming words from Scrabble tiles.

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

Data is serialized after processing the dictionary in order to speed up subsequent runs.

The program determines the comparison order of character frequencies by analyzing the dictionary:
comparing frequencies of characters that are more common in the dictionary first improves comparison performance significantly.

### Performance

On average, the application can query against a dictionary of 500,000 words in around 50 milliseconds.

See [the GitHub repository](https://github.com/bernardosulzbach/bigword).

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

## Pocket Statistics

Pocket Statistics is a website that will retrieve and analyze your Pocket data. [You can find it here](https://pocketstatistics.bernardosulzbach.com/).

It is deployed using an NGINX server (as a reverse proxy) and Waitress running on Arch Linux over IPv4 and IPv6.

Certbot (from Let's Encrypt) is used to provide (and regularly renew through a systemd timer) TLS certificates.

nftables is used to build an allowlist-based firewall and to prevent SSH brute-forcing and ICMP flooding.

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

## Self-organizing tree models for image synthesis

This is a C++ implementation of the main ideas from [Wojciech Palubicki, Kipp Horel, Steven Longay, Adam Runions, Brendan Lane, Radomír Měch, and Przemyslaw Prusinkiewicz. 2009. Self-organizing tree models for image synthesis. In ACM SIGGRAPH 2009 papers (SIGGRAPH '09), Hugues Hoppe (Ed.). ACM, New York, NY, USA, Article 58](https://doi.org/10.1145/1576246.1531364).

The code is fairly well-documented in order to help an interested reader better understand how the paper was implemented.

See [the GitHub repository](https://github.com/bernardosulzbach/self-organizing-tree-models).

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

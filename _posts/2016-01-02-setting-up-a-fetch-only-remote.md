---
layout: post
title: Setting up a fetch-only remote
---

It may happen that you have a remote to which you have push rights but will
never want to push. If you are afraid of pushing your changes to it by accident
or just want to play it safe, this command may be of assistance:

    git remote set-url upstream --push disallowed

This makes the push url of the `upstream` remote (use whatever name your remote
has) an invalid address that will prevent accidental pushes.

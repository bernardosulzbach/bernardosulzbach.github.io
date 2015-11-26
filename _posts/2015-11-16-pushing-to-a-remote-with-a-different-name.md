---
layout: post
title: Pushing to a remote branch with a different name
tags: [programming]
---

This post is just another small git tip. If you ever need to push to a remote
branch with a different name than your local branch, use

    git push origin local-name:origin-name

So if you want to push your local `dev` into your origin `review` you'd do

    git push origin dev:review

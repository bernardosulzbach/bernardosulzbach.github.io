---
layout: post
title: Git Push Current
---

Today I learned that the beloved message

    fatal: The current branch brunch has no upstream branch.
    To push the current branch and set the remote as upstream, use

        git push --set-upstream origin brunch

Can be avoided by setting push.default to current. This can be done with the following command.

    git config --global push.default current

As creating a remote branch rarely is an issue, this seems to me a much better default setting.

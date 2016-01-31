---
layout: page
title: Git notes
tags: [random]
---

## About this page

No. This is not a tutorial about git. I doubt you can go from zero to
anything using this. This is a collection of notes about git that I made
for myself. You are free to read them and benefit from them if they help
you at all, though.

## Terminology

In git, a **snapshot** is the state of a repository in a point in time.

## cherry-pick

In git, cherry-pick is used to apply the changes introduced by some
existing commits into the current working tree. The description of the
command:
> Given one or more existing commits, apply the change each one
> introduces, recording a new commit for each. This requires your
> working tree to be clean (no modifications from the `HEAD` commit).

## .gitgnore

### .git/info/exclude

If the exclusion pattern is somehow specific to your repository, then it
should go into the `.git/info/exclude` file, because it **is not
propagated during clone operations**. Its pattern format and treatment
is the same as .gitignore files.

## Ranges and Symmetric Differences

Ranges of commits `(a..b)` may be passed to `git log`. This takes all
commits reachable from `b` but not from `a`. For instance, git log
`master~12..master~10` returns `master~11` and `master~10`. One can also
pass the symmetric difference between two references `(a...b)`. (Notice
the third dot.) With `git log` this takes the set of commits that are
reachable from `a` **or** `b`, **but not from both**.

## Git Workflows

### Centralized Workflow

Like in Subversion, the Centralized Workflow uses a central repository
to serve as the single point-of-entry for all changes to the project.
Instead of trunk, the default development branch is called `master` and
all changes are committed into this branch. This workflow doesn't
require any other branches besides `master`.

### Feature Branch Workflow

The Feature Branch Workflow still uses a central repository, and
`master` still represents the official project history. But, instead of
committing directly on their local master branch, developers create a
new branch every time they start work on a new feature. Feature branches
should have descriptive names, like `animated-menu-items` or
`issue-1061`. The idea is to give a clear, highly-focused purpose to
each branch. Remember to do a `git rebase upstream` before pushing your
changes to the remote.

### Gitflow Workflow

The Gitflow Workflow is the ideal workflow for large teams or multi-team
projects. The `master` branch on this workflow serves only as an
abridged version of the story of the project. Actual development happens
on the `development` branch and feature branches interact with it only.
When a release is needed, a `release` branch is derived from the
`development` branch and polished until it can be squashed and merged
into the `master` branch.

### Forking Workflow

The Forking Workflow is the last and most modern Git Workflow. It gives
each and every developer their own fork of the repository. The result is
a distributed workflow that provides a flexible way for large, organic
teams (including untrusted third-parties) to collaborate securely. This
also makes it an **ideal workflow for open source projects**. It's
important to understand that the notion of an "official" repository in
the Forking Workflow is *merely a convention*. From a technical
standpoint, Git doesn't see any difference between each developer's
public repository and the official one. In fact, the only thing that
makes the official repository official is that it's the public
repository of the project maintainer or of the project's organization.
All of these personal public repositories are really just a convenient
way to share branches with other developers. Everybody should still be
using branches to isolate individual features, just like in the Feature
Branch Workflow and the Gitflow Workflow. The only difference is how
those branches get shared. In the Forking Workflow, they are pulled into
another developer's local repository, while in the Feature Branch and
Gitflow Workflows they are pushed to the official repository.

Note that it is possible to fork by SSH'ing into the server and running
`git clone` to copy it to another location on the server. Forking is
basically just a server-side clone.

This subsection is largely based on the amazing
[Comparing Workflows](https://www.atlassian.com/git/tutorials/comparing-workflows/forking-workflow)
by the guys at Atlassian.

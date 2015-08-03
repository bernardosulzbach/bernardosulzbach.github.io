---
layout: page
title: Writing good use cases
---

I am not a veteran at writing use cases, but I consider myself to be seasoned
enough to share a few key points with you.

# Definition

A use case is a textual representation (usually in the form of a list)
illustrating a sequence of events through which an actor (a human being, another
system or even time) interacts with a system to achieve a goal.

# Usage

Although use cases have been used for more than two decades, modern software
development methodologies (such as agile) can also employ use cases. Not only do
use cases provide a solid blueprint for your implementation, they also help you
brainstorm about what could go wrong.

# How to write use cases

According to [Martin Fowler](http://martinfowler.com/), "There is no standard
way to write the content of a use case, and different formats work well in
different cases."

I decided to write a simple and short use case to demonstrate a few points I consider essential.

**Write something down.** The point is that hardly ever you will get it right the
first time. You can perfect your use cases as much as you need when you have
time for it.

    Title: Create an account
    1. User pushes "Create an account".
    2. The user fills the four fields in.
    3. User pushes "Done."

**List your actors.** Anything that has behavior is considered an actor. Buyers,
sellers, assistants, and managers, for instance, are all actors. Note that I
did not call the buyer John and the seller Paul, instead of being specific
creatures, _actors are roles_.

    Title: Create an account
    Actors: User, Website, DB.
    1. User pushes "Create an account".
    2. The user fills the four fields in.
    3. User pushes "Done."

**Write your primary use cases before your secondary use cases.** Primary use
cases are the use cases where "everything goes according to the plan".
Secondary use cases diverge from this perfect scenario. It is common practice
to derive your secondary use cases from your primary ones. I've already
written the primary use case (the basic flow), now let's write what could be
our secondary use cases (alternative flows).

    Title: Create an account
    Actors: User, Website, DB.
    1. User pushes "Create an account".
    2. The user fills the four fields in.
    3. User pushes "Done."
    2.a.1. A script evaluates the password and considers it too weak.
    2.a.2. The user picks a stronger password.
    2.b.1. The DB identifies that the provided username is already in use.
    2.b.2. The user picks another username.

**Look for reuse opportunities.** If there is an evident pattern in your use
cases, it is very likely that a common object or a certain inheritance
hierarchy can be used to reduce code repetition and, therefore, speed up
development and ease code maintenance. If I had another use case, for
announcement publishing, for instance, the messages that pops up when the DB
checks that a unique value has already been used could be the same in both
pages, this would not only avoid repeated code and simplify maintenance but
would also increase design consistency.

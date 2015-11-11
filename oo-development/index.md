---
layout: page
title: Object Oriented Development
tags: [sidebar]
---

Some notes on object oriented software development.

# Use Case
A use case describes what your system does to accomplish a particular customer
goal. It is a technique for capturing potential requirements of a new system or
software change.

## See also

[Writing good use cases](/oo-development/writing-good-use-cases/).

## Textual analysis of a use case
Usually the nouns in a use case will become classes, but not every noun will be
a class. Some nouns may be external agents, and thus not need a class.

# Requirement
A condition or capability that must be met or possessed by a system to satisfy
a contract, standard, specification, or other formally imposed document.

# The essential questions of architecture
These questions help one determine to which parts of the system one should
dedicate more attention on the initial stages of the development process.

1. **Is it part of the essence of the system?**
   Only invest time on features that are at the core of the project.
2. **What does it mean?**
   Spend time on features you don't fully understand early in the development
   process.
3. **How is it implemented?**
   Learn how the advanced features are implemented at the beginning.

# Risk reduction
Development should always aim to reduce the risk of a project succeeding.
The question you need to be always asking yourself is "Will this reduce the
risk to my project succeeding?"
If the answer is negative, you probably can leave the task for a later stage of
the project.

# Design principles

## Open closed principle (OCP)
This principle states that software entities should be open for extension, but
closed for modification.

## Don't repeat yourself (DRY)
This is about having each piece of information and behavior in your system in a
single, sensible place.
This is not just about removing duplication; it is also about making good
decisions about how to break up the functionality of a system.

## The Single Responsibility Principle (SRP)
Each object should have a single responsibility and all its services should be
focused on carrying out that single responsibility.

## The Liskov Substitution Principle (LSP)
Subtypes should be substitutable for their base types.

# Refactoring
A good design helps one to maintain speed in software development. Refactoring
thus sometimes helps one develop software faster, because it keeps the quality
of the design of the system.

# Static factory methods Vs. Constructors
[In another page](/oo-development/static-factory-vs-constructors/).

# Code smells

[Primitive obsession](/oo-development/primitive-obsession/).

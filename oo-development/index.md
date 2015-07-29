---
layout: page
title: Object Oriented Development
tags: [sidebar]
---

Some notes on object oriented software development.

# Use Case
A use case describes what your system does to accomplish a particular customer goal.
It is a technique for capturing potential requirements of a new system or software change.

## Textual analysis of a use case
Usually the nouns in a use case will become classes, but not every noun will be a class.
Some nouns may be external agents, and thus not need a class.

# Requirement
A condition or capability that must be met or possessed by a system to satisfy a contract,
standard, specification, or other formally imposed document.

# The three essential questions of architecture
These questions help one determine to which parts of the system one should dedicate more attention on the initial stages of the development process.
1. Is it part of the essence of the system?
   Only invest time on features that are at the core of the project.
2. What does it mean?
   Spend time on features you don't fully understand early in the development process.
3. How is it implemented?
   Learn how the advanced features are implemented at the beginning.

# Risk reduction
Development should always aim to reduce the risk of a project succeeding.
The question you need to be always asking yourself is "Will this reduce the risk to my project succeeding?"
If the answer is negative, you probably can leave the task for a later stage of the project.

# Design principles
## Open closed principle (OCP)
This principle states that software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.

## Don't repeat yourself (DRY)
This is about having each piece of information and behavior in your system in a single, sensible place.
DRY is not just removing duplication; it is also about making good decisions about how to break up the functionality of your system.

## The Single Responsibility Principle (SRP)
Each object should have a single responsibility and all its services should be focused on carrying out that single responsibility.
Cohesion is another related to the SRP.

## The Liskov Substitution Principle (LSP)
Subtypes should be substitutable for their base types.

# Delegation
Delegation should be used when a class needs behavior that is not its responsibility.

# Composition
In composition, an object is composed of objects that do not exist outside the outer object. 

# Aggregation
Aggregation is not a synonym of composition. In aggregation, the objects the outer object is composed of also exists outside this object.
If the behavior provided by the component must exist outside the encompassing object, one should use aggregation.

# Prefer these three over inheritance!
By using delegation, composition and aggregation instead of inheritance, the system will usually be more flexible, maintainable, extensible and reusable.

# Loose coupling
Independent code is great for readability since we can make sense of it in isolation.

# Principle of least privilege
Code should be granted only the amount of privilege and access that it needs to accomplish its designated task.

A good design is essential to maintaining speed in software development. Refactoring helps you develop software more rapidly, because it stops the design of the system from decaying.

Design reviews are likely to be better using UML.

Code reviews consist of reading and understanding the implementation.

# Cohesion
A cohesive class does one thing really well and does not try to do or be something else. All the methods in a class should be related to the name of the class to some extent. 
When you fundamentally change what an application does you may have to make lots of changes to a design that's already cohesive and loosely coupled.
So cohesion isn't always a test of how easy it is to change software; but in cases where you're not dramatically changing how software works, highly cohesive software is usually easy to change.
 
# Long methods
How do you identify the clumps of code to extract? A good technique is to look for comments. They often signal this kind of semantic distance.
A block of code with a comment that tells you what it is doing can be replaced by a method whose name is based on the comment. Even a single line is worth extracting if it needs explanation.
 
# Domain analysis
The process of identifying, collecting, organizing, and representing the relevant information of a domain, based upon the study of existing systems and their development histories,
knowledge captured from domain experts, underlying theory, and emerging technology within a domain.
 
# Solving big problems
The best way to look at a big problem is to view it as a collection of smaller problems.
Just like in small projects, start working on big projects by gathering features and requirements.
Features are usually "big" things that a system does, but also can be used interchangeably with the term "requirements."
Commonality and variability give you points of comparison between a new system and things you already know about.
Use case diagrams are more focused on the big picture, while use cases usually are detail-oriented.
The use case diagram should account for all the features in your system.
Domain analysis is representing a system in a language that the customer will understand.
An actor is anything that interacts with your system, but isn't part of the system.

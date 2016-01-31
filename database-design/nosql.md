---
layout: page
title: NoSQL
tags: [database-design]
---

## Appearance

Relational databases arose in the 80's. NoSQL databases are much more recent.

## Reason

The problem with relational databases was that a single logical structure in the
application ends up being split into several rows and tables. This is known as
**impedance mismatch**: the difficulties encountered when trying to map
an object into a table.

This led to **object databases**. They did not become popular because many
systems used relational databases for integration. This way, relational has
dominated into the 2000s. The change that happened to bring attention no NoSQL
was the popularization of the Internet. Some sites got a lot of traffic and
needed to scale. Using many simple computers, as Google and Facebook do is not
relational database friendly, as these databases are not easily distributed.

NoSQL (the term) was a hashtag someone came up with for a meetup Johan
Oskarsson proposed to discuss the problems with relational databases. Defining
NoSQL is almost impossible, but it is possible to list some common
characteristics of NoSQL databases:

- They are non-relational.
- Most are cluster-friendly.
- Most are open source.
- They are related to 21st century web.
- They are schema-less.

There are four different data models NoSQL databases use.
The simplest one is **key-value**. It's like a persistent hashmap that can
store any kind of data.

There is also the **document model**. It is similar to JSON. Differently
from a key-value, this is much more transparent about what the data is.

Having no schema adds a lot of flexibility. But note that schema-less is not
accurate as most if not all documents have an *implicit schema*. For
instance, all items may have `price` even if it is not required.

Most key-value databases allow you to store metadata about the values, what
makes them somewhat similar to document databases.

Document databases usually provide access by ID, what further blurries the line
between key-value and document databases.

There is also the **column family model**, which is slightly more complex.
In these databases, a row key maps to a set of column families.

These three types of NoSQL databases are also known as **aggregate
models**. They are better at clustering because each node gets a set of
aggregates that contain all the data a query needs and thus avoid the need of
building the result from small pieces obtained from different nodes.

If you need to slice data in several different ways, aggregate databases are not
a good idea.

The fourth and last type of NoSQL database is **graph databases**. These go
in the opposite direction of the other three, making the structure even less
rigid than a table. All four are schema-less and which one you use depends on
how do you work with your data.

If you use aggregates all the time, aggregate oriented databases are your best
bet. If you need to really break things up and jump around in a complex
structure, graph databases are the way to go. But in the end what works best for
you may be the good and old tabular structure provided by relational databases.

NoSQL databases ease development when there are natural aggregates and when
there is just too much data for a single server.
Aggregate-oriented databases are ACID within aggregates, concurrency issues show
up when a single transaction must change multiple documents.

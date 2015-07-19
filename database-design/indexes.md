---
layout: page
title: Indexes
---

# Description

Database indexes are data structures that improve the speed of data retrieval operations on a database table at the cost of additional writes and storage space.

Indexes can be created using one or more columns of a database table. These values are kept sorted, thus speeding up searches.

# Types

Indexes can be unique or non-unique. Non-unique indexes allow the indexed columns to contain duplicates.

# Performance

Be aware that while indexes speed up queries they also slow down insertions and updates.

# Syntax

    CREATE INDEX <indexname> ON <tablename> (<column>, <column>...);

    CREATE UNIQUE INDEX <indexname> ON <tablename> (<column>, <column>...);

    DROP INDEX <indexname>;

# Ordering

To specify sort order, the keywords `ASC` and `DESC` can be placed after each column name.


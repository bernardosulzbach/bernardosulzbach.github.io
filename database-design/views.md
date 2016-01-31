---
layout: page
title: Views
tags: [database-design]
---

# Description

Views are also called *named queries* and *stored queries*.
They don't take up any space in disk for data storage because only the query is stored.
The tables a view references are called the *base tables* of that view.

# Syntax

    CREATE VIEW <name> AS <query>;

    DROP VIEW <name>;

# Materialized views

Materialized views store the query result in disk.
They are used when the user simply can't be kept waiting for the query to finish.
Many views are useless when they are outdated and must be re-run whenever there is a change to any of the tables that they are based on.


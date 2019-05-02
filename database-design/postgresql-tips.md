---
layout: page
title: PostgreSQL tips
tags: [database-design]
---

This tips were inspired, among other sources and personal experience, by [the
PostgreSQL Wiki](https://wiki.postgresql.org).

# Do not use NOT IN

Using `NOT IN` or a combination such as `NOT (x IN (...))` is a bad idea. If
you need something like `NOT IN (SELECT ...)` you can rewrite it using `NOT
EXISTS`.

One of the main reasons for this is that if there is NULL in the set of values,
`NOT IN` will never evaluate to `TRUE`. This is because when comparing a value
that is not in the set to `NULL`, `NULL` will be generated. `NOT (NULL)` is
still `NULL`, so it is not possible for any value to evaluate to `TRUE` if
there is a `NULL` in the exclusion set.

The other reason is because the query planner, as a consequence of the reason
outlined above, might make queries with `NOT IN (SELECT ...)` very slow.

However, **it is OK** to use `NOT IN` with a list of constants.

# Do not use BETWEEN

`BETWEEN` uses a closed-interval comparison, which always includes both ends.
Even if this sometimes is what you want, using it is still considered a bad
practice by many, as it will often return unexpected results, mainly if dealing
with dates.

For instance, the two queries below might have a non-empty intersection, as a
timestamp of 2019-01-02 00:00:00.000000 will match both queries.

```sql
SELECT ... WHERE time BETWEEN '2019-01-01' AND '2019-01-02';
SELECT ... WHERE time BETWEEN '2019-01-02' AND '2019-01-03';
```

# Do not use timestamp (without time zone)

Use `timestamp with time zone` instead. Timestamp with time zone records a
point in time in UTC, performing the necessary conversions and ensuring
arithmetic works as expected. **However, despite what the name suggests, this
type does not store the entered time zone**.

## Do not use timestamp even if you are converting to UTC

There is no way for the database to know that UTC is the timezone of the stored
values if you are using `timestamp`. This complicates otherwise simple time
calculations, because now you must specify the time zones.

# Do not specify a precision for timestamps

This does not truncate values, it rounds them. This can cause unexpected
behavior such rounding `now()` to a moment in the future.

# Prefer text over other types for text storage

Most importantly, try to never use `char(n)` as it has some very strange
behavior and even though you might think it is a fixed-width type, it is not as
the actual number of bytes varies since characters may take up more than one
byte.

Unless you have a very good reason to limit the length of a text column, do not
use `varchar(n)`, use `varchar`, or, better yet, `text`.

# Avoid using the money data type

The currency used for the money data type is the same for the whole database.
Additionally, it's rounding behavior is likely not what you want. Using a pair
of `numeric` and a currency value is a much better solution.

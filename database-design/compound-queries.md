---
layout: page
title: Compound queries
---

# Definition

Compound queries process the result of multiple queries from left to right using
three relational algebra operations: union, intersection and difference. When
you cannot express all you need with a single `select` statement, you can use a
compound statement of two or more `select` statements to retrieve the data.

# SQLite

SQLite has the keywords `union`, `intersection` and `except` for union,
intersection and difference, respectively. In this article, I will be using
SQLite to demonstrate compound queries.

# Requirements

A compound query **requires that its arguments have the same number of columns**
and allows only one `order by` clause, which must be at the end of the compound
query and apply to the combined result.

# Union

In SQL, `union` combines two relations and eliminates duplicates along the way.
If you do not want to get rid of duplicate rows, you can use `union all`. In a
hypothetical database where I have 3 tables, `users`, `accounts`, and
`closed_accounts`, the following SQL statement would give me the list of users
that have at least one account, either opened or closed.

{% highlight sql %}
-- All users that have an account.
select users.id as id, name from users
inner join accounts on accounts.owner_id=users.id
union select users.id as id, name from users
inner join closed_accounts on closed_accounts.owner_id=users.id
order by users.id;
{% endhighlight %}

# Intersect

Suppose now that what I want is to find all users who have both open and closed
accounts. The following statement should suffice.

{% highlight sql %}
-- All users with both open and closed accounts.
select users.id as id, name from users
inner join accounts on accounts.owner_id=users.id
intersect select users.id as id, name from users
inner join closed_accounts on closed_accounts.owner_id=users.id
order by users.id;
{% endhighlight %}

# Except

Lastly, getting a list of all the users that only have closed accounts could be
done with the following statement.

{% highlight sql %}
-- All users that only have closed accounts.
select users.id as id, name from users
inner join closed_accounts on closed_accounts.owner_id=users.id
except select users.id as id, name from users
inner join accounts on accounts.owner_id=users.id
order by users.id;
{% endhighlight %}

---
layout: page
title: Node.js notes
tags: [random]
---

NPM
===
It is considered a good practice to specify an engines key with your current
version of Node.

By default, npm does not save installed dependencies to package.json, but you
should track your dependencies. For apps, another good idea is to keep track of
exact versions of your dependencies.

Organization
============
Only use lowercase filenames.

Clustering
==========
Deploying a non-clustered node app on a large server is a huge waste of
resources.

A fundamental idea is never to do CPU-intensive operations on the Node.js
instances that the clients talk to.

Invoking callbacks multiple times is a common source of bugs. Avoiding callback
hell (deeply nested callbacks) is also important to maintain code readability.

Anything that should happen after a callback has fired needs to be invoked from
within it.

Throwing errors from inside callbacks is usually a source of bugs. Encompassing
try-catch blocks may be out of scope when the callback is asynchronously
called.

The integer is a lie
====================
Numbers in JavaScript are floating points - **there is no integer data type**.

Free laugh:

    Math.pow(2, 53) + 1 === Math.pow(2, 53)  // evaluates to true.

Solution
--------
If you ever need to deal with large numbers, there are big integer libraries
that implement the important mathematical operations on large precision
numbers, such as `node-bigint`.

Using modules
=============
Node treats each file as an isolated module. A file can export its
functionality by adding properties to the `exports` object:

    exports.validate = ...

When this is done, anyone requiring this file will be given **an object** with
the property function `validate`.

What if we want to export this function directly, and not as the property of
some object? We can **overwrite** `exports` to do this, but we must not treat
it as a global variable then:

    module.exports = ... 

Notice that we are treating `exports` as a property of the module object. The
distinction here between `module.exports` and `exports` is very important, and
is often a cause of frustration among inexperienced developers.

Supervisor programs
===================
A supervisor program can orchestrate your Node.js application. It is a good
practice to fail fast: if an unexpected error occurs, do not try to handle it,
rather let your program crash and have the supervisor restart it.

Performance
===========
Why is declaring a variable outside any function's scope in a browser slower
than in Node.js? Within a web browser, the variable's scope makes it global
and therefore binds it as a property of the huge `window` object. Therefore,
declaring this variable in a web browser requires resolving a property within
the heavily populated `window`.

In Node.js, however, declaring any variable outside of any function's scope
binds it only to the module's own scope which therefore makes it much easier
and faster to resolve.

---
layout: post
title: Getting the size of an object in Python
---

Recently, I found myself wondering how much memory a Python list I had in my
environment was using. So I searched and found the following very handy
function for the curious minds or desperate debuggers.

    sys.getsizeof(object[, default])

      Return the size of an object in bytes. The object can be any type of
      object. All built-in objects will return correct results, but this does
      not have to hold true for third-party extensions as it is implementation
      specific.

      Only the memory consumption directly attributed to the object is
      accounted for, not the memory consumption of objects it refers to.

      If given, default will be returned if the object does not provide means
      to retrieve the size. Otherwise a TypeError will be raised.

      getsizeof() calls the object's __sizeof__ method and adds an additional
      garbage collector overhead if the object is managed by the garbage
      collector.


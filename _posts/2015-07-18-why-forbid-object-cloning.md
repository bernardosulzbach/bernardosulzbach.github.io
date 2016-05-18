---
layout: post
title: Why Forbid Object Cloning
---

These are the reasons why I chose to forbid object cloning:

+ cloning is a risky extralinguistic object creation mechanism;
+ cloning demands adherence to thinly documented conventions;
+ cloning conflicts with the proper use of final fields;
+ cloning throws unnecessary checked exceptions;
+ cloning requires casts.

## How cloning conflicts with final fields

Say Foo has a final Bar field. Bar is mutable but the field is final. When
cloning Foo, you would need to fix the field by doing:

```java
// ...
Foo clone = (Foo) super.clone();
clone.bar = (Bar) bar.clone(); // Impossible !
return clone;
// ...
```

which is impossible.

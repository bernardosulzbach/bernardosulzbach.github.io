---
layout: page
title: Primitive obsession
---

# Definition

**Primitive obsession** is the usage of primitive types to represent domain ideas.

To list a few examples:

* Using a String to represent an ID or tag.
* Using a floating-point number to represent a percentage.
* Using a char to represent a unit.

# Why not to use primitive types

One of the main reasons to use Reference Data Types instead of Primitive ones is
that the former is far superior at ensuring encapsulation. Very often, only some
of all possible values that a primitive can assume are legal values. When this
is the case, one should check that this given primitive is never set to an
invalid value, what could be done in a setter method. Alternatively, one could
create a Reference Data Type for this field and let its constructor validate the
data. This approach not only better organizes program logic but also provides
stronger encapsulation.

# Real-world example

To demonstrate this, I will use a code snippet from an open-world single-player
role-playing-game I am currently developing called
[Dungeon](https://github.com/mafagafogigante/dungeon).

```java
public abstract class Entity implements Selectable, Serializable {

  public final String id;
  public final String type;
  public final String name;

  ...

}
```

id does not name a type, and neither does type or name.

# The ID classes

As ID is not as generic as a String and should be well encapsulated, I've
decided to create the ID class.

```java
public final class ID implements Serializable {

  private final String id;

  public ID(String id) {
    this.id = id;
  }

  public String getId() { return id; }

}
```

This class seems too short to be useful, but it has yet another positive aspect:
a descriptive name.

# The cascading effect

This change, however, has a cascading effect. Fortunately enough, in this case,
it is a pretty small one. All I needed to do was to change

```java
public String getId() { return id; }
```

to

```java
public String getId() { return id.getId(); }
```

in the Creature and Item classes.

## Removing repeated code

Two classes in the same hierarchy with identical methods does not sound good.
After noticing the code repetition, I removed the getter from both classes and
added a public getter to the Entity class (that is the superclass of both
Creature and Item).

```java
public String getId() { return id.getId(); }
```

# Result

Now the ID of an Wolf is an ID object and so is the ID of a Stick. They are not
simple Strings of text, but a specific kind of object in my application.

# Improving the ID class

There are a few restrictions that all IDs follow. So we can improve the class to
account for this.

```java
public final class ID implements Serializable {

  private final String id;

  public ID(String id) {
    // Check that the provided String is a legal id.
    // If it wasn't, fix it and log that an illegal id was provided.
    this.id = id;
  }

  public String getId() { return id; }

}
```

Now the ID constructor will parse the given String and make sure that it is a
valid ID. If it finds an illegal character, it will fix it and log a warning.
This verification could have been done in a setter of the Entity class or even
in a distant method in an Utils class. However, neither of these places are as
appropriate as the class ID itself.

# Summary

In Object Oriented Programming, it is a good practice to let objects represent a
concept from the domain. Implement a Money class if you need to deal with money,
a Point class to designate a point in space, a Period class to represent the
distance between two dates. The little overhead from the extra layer of
abstraction will likely be worth it. Ultimately, by avoiding primitive obsession
you will achieve better encapsulation and improve code maintainability.

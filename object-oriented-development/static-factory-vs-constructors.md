---
layout: page
title: Static factory methods Vs. Constructors
---

When it comes to object creation, a class can provide static factory methods in
addition to (or instead of) public constructors. This post presents a
comparison of static factory methods and public constructors based on the
second edition of Effective Java.

# Advantages of static factory methods

**Unlike constructors, static factory methods have names**. An example of this
advantage is BigInteger.probablePrime, a method whose name describes the
contents of the object it returns. **Static factory methods may return already
existing objects**. This allows a class to avoid creating identical immutable
objects. Therefore, it can greatly improve performance if equivalent objects
are requested often. Classes that keep track of already created instances are
said to be _instance-controlled_. Immutable _instance-controlled_ classes can
make the guarantee that no two equal instances exist (this is, if a.equals(b),
then a == b). This allows client code to use the == operator, which may improve
performance slightly. Enumerated types provide this guarantee.

**Static factory methods can return an object of any subtype of their return
type**. This allows for an API to return objects without making their classes
public. This is common in interface-based frameworks, where the return types of
the static factory methods are interfaces. As Interfaces cannot have static
methods, by convention, static factory methods for an interface named `Type`
are put in an non-instantiable class called `Types` (remember using `Executors`
to get an `Executor`?). The Java Collections framework, for instance, has many
nonpublic classes that implement its different Interfaces. 

**Static factory methods may also reduce the verbosity of creating
parameterized type instances**. If there is a static factory method such as

    public static <T> Bucket<T> newInstance() {
        return new Bucket<T>();
    }

then it is possible to use

    Bucket<Water> myBucket = Bucket.newInstance();

making the code shorter and clearer (the ability of the compiler to figure out
the type **T** is known as _type inference_). The improvement is more
noticeable for big and complicated parameterized types. Of course, if you can
use Java 7 (or a newer version), the diamond operator allows you to omit the
redundant parameters.

# Disadvantages of static factory methods

**Providing only static factory methods makes it impossible to subclass classes
without public or protected constructors**. This, however, also encourages
programmers to use composition over inheritance, which is good.

**Static factory methods are not readily distinguishable from other static
methods**. Sometimes it may be hard to figure out how to instantiate a class
that provides static factory methods instead of public or protected
constructors. To solve this problem, it is a good idea to use common names for
static factories, such as `getInstance`, `newInstance`, `getType`, and
`newType`.

# Wrapping up

Static factory methods and public constructors both have their uses and merits.
Often static factories are better, so avoid the urge to provide public
constructors without even considering static factories.

---
layout: page
title: Distributed programming
tags: [random]
---

**Java threads**

In Java, multiple threads can have the same name. However, the IDs are unique
among the living threads. IDs of finished threads can be reused.

Most modern Java virtual machines use native threads which are scheduled by the
underlying operating system.

**Java synchronization**

It is safe for a synchronized method to call another synchronized method.

The Timer class is a facility for threads to schedule tasks for future
execution in a background thread. These tasks may be scheduled for one-time
execution, or for repeated execution at regular intervals.

Interruptions (by calling `interrupt()` in a Thread) will raise
`InterruptedException` on certain methods. Otherwise, detecting them requires
checking the return value of `interrupted()`.

The main difference between a `CountDownLatch` and a `CyclicBarrier` is that
the first blocks until a certain number of calls to the countdown method is
made while the second locks until a certain number of blocked threads if
reached.

**Synchrony**

In a synchronous system, there is a known fixed upper bound on the time
required for a message to be sent from one processor to another and a known
fixed upper bound on the relative speeds of different processors. In an
asynchronous system no fixed upper bounds. In partial synchrony, there are
fixed bounds, but they are not known a priori, so one has to design protocols
that work correctly in the partially synchronous system regardless of the
actual values of such bounds.

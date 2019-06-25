---
layout: page
title: Distributed programming
tags: [random]
---

# Java

## Java threads

In Java, multiple threads can have the same name. However, the IDs are unique
among the living threads. IDs of finished threads can be reused.

Most modern Java virtual machines use native threads which are scheduled by the
underlying operating system.

## Java synchronization

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

# Synchrony

In a synchronous system, there is a known fixed upper bound on the time
required for a message to be sent from one processor to another and a known
fixed upper bound on the relative speeds of different processors. In an
asynchronous system there are no fixed upper bounds. In partial synchrony,
there are fixed bounds, but they are not known _a priori_, so one has to design
protocols that work correctly in the partially synchronous system regardless of
the actual values of such bounds.

# Parallel programming

A good solution must scale well with both the input size and with the processor
count.

Sometimes, a good approach towards a parallel solution is to analyze what is
the biggest bottleneck of a sequential solution.

# MPI

MPI is a standard for portable message-passing designed by a group of
researchers from academia and industry to function on many parallel computing
architectures.

`MPI_Init` must be called in the source. All code before it might be executed
by all processes.

`MPI_Comm_rank` returns the rank (identification) of the process.

`MPI_Comm_size` returns the size of the communicator.

`MPI_Finalize` should be at the end of the program to ensure all processes
synchronize at the end.

`MPI_Send` is responsible for sending a message to another process. It does not
return until the message data and envelope have been safely stored away so that
the sender is free to modify the send buffer. The sender must always specify a
tag for the message.

`MPI_Receive` can receive any tag of message from any sender. However, it can
use a specific tag so that it will block until a message with the tag of
interest arrives. It can also block until a message from a specific sender
arrives.

If the receiver does not use matching parameters for size, for instance, the
message might be truncated. This is implementation-dependent.

There are also non-blocking sending and receiving versions of these functions.

Lastly, there are also functions for broadcasting, such as `MPI_Bcast`, and
selectively sharing data.

`MPI_Scatter` has a designated root process which sends data to all processes
in a communicator.

The main difference between `MPI_Bcast` and `MPI_Scatter` is that `MPI_Bcast`
sends the same data block to all processes, but `MPI_Scatter` sends different
chunks of the data block to different processes.

`MPI_Gather` is the inverse of `MPI_Scatter`. Instead of sending chunks of the
data block from one process to many processes, it gathers these chunks from
many processes into a single data block. Lastly, `MPI_Allgather` works the same
way as `MPI_Gather`, but instead of gathering the data block in a single
process, it allows for all processes to end up with the complete data block.

[This
tutorial](https://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/)
has some really good illustrations of this process.

# OpenMP

Parallelizing compilers might not optimize the real bottleneck as they do not
know what the input data is. With domain-specific knowledge, the programmer can
do a better job at optimizing the code by inserting directives right at the
loops which can benefit from parallelization.

OpenMP is a fairly mature and available standard.

In OpenMP, there is a separation between shared (global) variables and private
(local) variables. The OpenMP execution model is the fork and join model, in
which there are parallelized sections of the code in which the worker threads
kick in to speed up the application.

If-clauses might be used to prevent parallelization when the instances are too
small to benefit from it.

The `nowait` clause can be used in some directives to make threads not wait for
synchronization.

The `single` constructor makes it so that only one thread executes the block.
The `master` constructor might be used if the master thread must be the one
executing the block.

The `critical` constructor makes it so that only one thread at a time might
enter the block.

# Big data

There are five V's of big data: volume, velocity, variety, veracity, and value.
Big data proposes the analysis of all the available data at once rather than
multiple analyses of small subsets.

# Hadoop

Hadoop is an open-source alternative to Google's MapReduce, which abstracts the
parallelization problem by allowing the programmer to think in terms of a
mapping method (which performs filtering and sorting) and a reducing method
(which performs a summary operation).

The data is transformed into (key, value) tuples.

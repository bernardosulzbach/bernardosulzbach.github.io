---
title: CPU Cache Basics
layout: post
---

This post covers fundamental cache concepts such as locality of reference,
mappings, and why caching is important.

# Caching basics

Caching is used to improve CPU performance. Main memory is far from the CPU and
also operates in a much lower frequency. Storing the data and the code that the
processor is most likely to use next close to it and in a faster memory
improves its overall performance.

It is worth noting that some designs split the cache into I-cache (instruction
cache) and D-cache (data cache).

## Locality of reference

Caching is based on locality of reference. This means that usually access
patterns exhibit temporal locality (data that has already been requested is
likely to be requested again soon) and spatial locality (data physically near
data that has been accessed recently is more likely to be accessed).

### Notes on locality of reference

In some situations, temporal locality works against us. For instance, when
playing media files storing already played memory blocks in the cache is usually
is a waste of space.

While temporal locality implies spatial locality (reused data always presents
some physical pattern), spatial locality does not imply temporal locality. Take
for instance different functions in a business application. The user may never
request more than two of the three hundred available operations, rendering most
of the caching that could be performed based on spacial patterns useless.

Many applications have very different memory access patterns for code and data.
Take, for instance, a media player which has an excellent temporal locality for
code (the code that renders a frame is always reused) but a terrible spatial
locality for data (the bytes that make up a frame are hardly ever useful
again). This explains why some designers split the cache into I-cache and
D-cache as mentioned above.

## Tag RAM

When the CPU requests a byte from a particular block from RAM, it needs to
determine if it is in the cache or not and, if it is, where it is. For this
reason there exists a piece of memory called a tag associated with each frame
of the cache. This piece of information allows the CPU to know about the blocks
currently held in that cache frame. This memory needs to be very fast in order
to reduce the overhead of cache lookup.

## Mappings

Essentially, there are three ways to use tags to map RAM blocks to block frames
in the CPU cache.

### Fully Associative Mapping

This is arguably the simplest possible mapping scheme. This mapping allows for
any memory block to occupy any cache frame. This simplicity comes at a price: in
order to determine whether or not a memory block is in the cache, the CPU has to
search all of the cache frames.

### Direct Mapping

In direct mapping, each cache frame can only contain a memory block from a
subset of all memory blocks. The memory is evenly divided among the available
cache frames, in such a manner that if the CPU needs to fetch a certain memory
block there is only one cache frame it needs to check. This method solves the
problem of lengthy cache scans of fully associative mapping at the expense of
not allowing memory blocks that are mapped to the same cache frame to be in the
cache at the same time, which can severely hinder performance in some scenarios. 

### N-Way Set Associative Mapping

The third type of cache mapping tries to lessen the conflicts introduced by
direct mapping. This method may be seen as a mixture of both methods mentioned
above. In set associative mapping, there are multiple cache blocks in each cache
frame, and each cache frame is responsible by a subset of main memory. This way
the same memory block has more than one cache block it can be assigned to and
the chance of it evicting another relevant block is reduced. One can imagine,
for the sake of visualization, set associative mapping as multiple smaller fully
associative mappings.

This is the most commonly used form of mapping.

## Cache misses

Cache miss is a state where the data requested by the CPU is not found in the
cache. There are basically three types of cache miss:

### Compulsory miss

This is what the miss is called because the sought after data was never loaded
into cache. This type of miss is also known as a cold miss.

### Conflict miss

A conflict miss occurs when the CPU tries to find a memory block in the
corresponding cache frame but the frame is already filled with other memory
blocks.

### Capacity miss

This last type of miss happens when the block containing the needed data has
already been evicted from the cache.

## Writing policies

So far only reading from cache has been discussed. However, data is also being
written as most computers store the results of their computations.

There are essentially two writing policies for caches, and different
combinations of them may be used. *Write-through* is the simplest one and the
*safest*, from a multithreaded point of view. It consists of writing changes to
all levels of the cache back to main memory. The other solution is
*write-back*, which consists of only writing the changes to the cache level
below once the cache block is evicted. This model makes guaranteeing proper
synchronization much more complex in order to improve performance.

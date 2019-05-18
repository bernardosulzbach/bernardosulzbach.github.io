---
layout: page
title: Communication protocols
tags: [random]
---

**What are the main differences between IPv4 and IPv6 datagrams?**

IPv6 has expanded addressing capabilities, as it uses 128-bit addresses instead
of 32-bit addresses. In addition to unicast and multicast, IPv6 has also
anycast, which allows a message to be delivered to any host of a set of hosts.

The header has a fixed size of 40 bytes, which simplifies hardware
implementations.

The header also has the traffic class (8 bits) and the flow label (20 bits)
fields.

IPv6 does not allow for fragmentation and reassembly at intermediate routers.
It also does not have a checksum (which was deemed unnecessary once that
Ethernet, UDP, TCP, and several other protocols already have checksums).
Lastly, it does not have the variable length options field that IPv4 did.

**What are the main IPv6 routing performance improvements?**

+ IPv6 does not allow for intermediate systems to perform fragmentation.
Therefore, packets that are too large just cause an error to be sent back to
the sender, instead of requiring fragmentation to take place in intermediate
nodes.
+ IPv6 does not require a checksum to be recomputed at every hop.
+ IPv6 has a fixed header size.
+ As IPv6 more often allows for direct addressing of the receiver, it is
possible to not use NAT or use it less often, which should improve performance
of the network.

  **TODO: find some more arguments.**

**What are the transition mechanisms between IPv4 and IPv6?**

+ **Dual-stack**. This approach requires IPv6 nodes to also have a complete IPv4
implementation.
+ **Tunneling**. This solution uses IPv4 datagrams to carry IPv6 datagrams as if
they were just data between IPv4 nodes. This preserves IPv6-specific fields
which are not preserved in the dual-stack approach.
+ **Protocol translation**. This alternative is very complex and expensive.
However, as it completely translates IPv6 traffic into IPv4 traffic, it has to
be used if legacy software or hardware cannot be updated to support IPv6.

**What is the high-level architecture of the Internet?**

The Internet is a set of autonomous systems which use a common protocol to
communicate to each other what the current topology is. Within these autonomous
systems, any routing algorithm might be used to define the best routes for
traffic. In smaller, access networks, link-layer switches are more prevalent
than routers. Lower-tier ISPs connect their autonomous systems to higher-tier
ISPs in order to be able to reach all parts of the Internet.

**What is an AS?**

An AS or autonomous system is a group of routers under the same administrative
control. All the routers within an AS have to run the same routing algorithm
and have some information about each other. One or more routers in an AS have
the added task of forwarding packets to outside the AS. These routers are
called gateway routers.

**What is an ISP?**

An ISP or Internet service provider is an organization that provides services
for using the Internet. There are commercial, community-owned, non-profit, and
privately owned ISPs.

**What are the ISP levels?**

+ Tier 1 ISPs (or backbone ISPs) maintain default-free routing tables. At
points of presence, they provide connectivity with tier 2 ISPs and connect to
other tier 1 ISPs at peering locations.
+ Tier 2 ISPs (or regional ISPs) are intermediate providers, which operate at a
regional or national level.
+ Tier 3 ISPs (or access ISPs) are access providers for end users, such as
DSL/Cable-Modem providers.

Tier 1 ISPs almost never pay for IP transit, while tier 3 ISPs almost always
pay for IP transit.

**A point of presence (PoP)** is where customer ISPs connect to provider ISPs.

**Multi-homing** occurs when a customer ISP connects itself to several
providers in order to improve fault-tolerance or throughput.

**What is peering? What is peering through traffic exchange point?**

In order to avoid paying for expensive provider ISP traffic, neighboring
customer ISPs can exchange traffic directly. Just as tier 1 ISPs usually peer
settlement-free, customer ISPs also usually peer settlement-free, that is, not
paying for traffic.

An Internet exchange point (IXP) is a meeting point where multiple ISPs can
peer together. They are usually set up by third-party companies.

**What are the BGP mechanisms for traffic engineering between autonomous
systems?**

The AS path can be made longer artificially by repeating parts of it. This way,
through BGP, an AS can decide from which AS it would rather receive traffic.
For instance, an AS A1 might tell one of its neighbors that going through A1
requires 10 more hops than it actually takes, therefore making other ASs more
likely to use other neighbors to reach A1.

**What are the differences between eBGP and iBGP?**

A BGP session that spans multiple ASs is called an external BGP (eBGP) session
and a BGP session between routers in the same AS is called an internal BGP
(iBGP) session. Certain attributes such as local preference are sent to iBGP
peers but not to eBGP peers. Additionally, routes received from an eBGP peer
can be advertised to both eBGP and iBGP peers. However, routes received from an
iBGP peer cannot be advertised to other iBGP peers, only to eBGP peers. This is
required to prevent loops.

**What are the QoS principles?**

0. Packet marking is needed for routers to distinguish between different
traffic classes.
0. Protection (isolation) from other traffic classes must be provided by the
network.
0. While providing isolation, it is desirable to use resources as effectively
as possible.
0. The network may block a call (request) if it cannot meet its needs.


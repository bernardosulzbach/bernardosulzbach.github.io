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

**What are the transport abstractions used by TCP and UDP?**

TCP uses a byte stream abstraction, while UDP uses a datagram abstraction.

**How congestion control and flow control interact?**

**How does the receiver in TCP handle out-of-order segments?**

This is not specified. It is up to the implementation.

**How TCP calculates timeouts?**

TCP keeps an adaptive calculation to determine the timeout. If the timeout is
too short, it will cause unnecessary retransmissions. If the timeout is too
long, the sender will be slow to react to losses.

There are no timers per segment, timers are per connection. The timer can be
understood as the timer for the oldest segment which has not yet been
acknowledged. When a timeout occurs, the segment is retransmitted and the timer
is restarted.

The timeout is the estimated round-trip time plus a "safety margin".

The estimated RTT ($$E_{RTT}$$) is an exponential weighted moving average. It
uses a parameter $$\alpha$$ and evaluates the following expression.

$$E_{RTT}(n) = (1 - \alpha) E_{RTT}(n - 1) + \alpha S_{RTT}(n - 1)$$

Typically, $$\alpha$$ is 0.125.

In which $$S_{RTT}$$ is the measured time from segment transmission until
acknowledgement receipt. This calculation ignores retransmissions.

The deviated RTT ($$D_{RTT}$$) is evaluated given by the following expression.

$$D_{RTT}(n) = (1 - \beta) D_{RTT}(n - 1) + \beta \left|(S_{RTT}(n - 1) - E_{RTT}(n - 1)\right|$$

Typically, $$\beta$$ is 0.25. Larger values for $$\beta$$ will make deviations
weight more into the timeout.

In both of these formulas, having larger values of the factor $$\alpha$$ or
$$\beta$$ makes the formula more sensitive to recent values. Conversely,
smaller values make the metric to be more based on the past.

The timeout can be evaluated through the following formula.

$$T = E_{RTT}(n) + 4 D_{RTT}(n)$$

**What are the ways of TCP detecting losses?**

Timeouts and three ACKs for the same segment. Retransmitting after three ACKs
is known as fast retransmit.

**What is TCP Fast Recovery?**

In Fast Recovery, which is entered after three duplicate ACKs, the congestion
window is halved and then grows linearly. After a timeout, we are back to the
slow start, in which the congestion window has size = 1 MSS and grows
exponentially.

The reasoning behind this is that multiple duplicate ACKs indicate a network
capable of delivering some segments. However, a timeout indicates a more
serious congestion or even failure of the network.

A variable controls the slow start threshold, which determines when the
connection changes to AIMD. It is typically set to half the congestion window
just before the loss event.

**What are the studied TCP flavors?**

*Tahoe*

*Reno*

*NewReno*
- Refined Reno's Fast Recovery.
  + When selective acknowledgement is not being used and the algorithm enters Fast Recovery triggered by three duplicate acknowledgements, it does not know which segments to retransmit other than the first unacknowledged segment.
    NewReno gives special treatment to partial acknowledgements that might happen during Fast Recovery.
    It does not halve the congestion window if another segment was also not delivered, like Reno would, and will keep retransmitting the first unacknowledged segment until it leaves Fast Recovery.
    Because NewReno can send new packets at the end of the congestion window during Fast Recovery, high throughput is maintained during the Fast Recovery process.
    When it enters Fast Recovery, it stores the highest unacknowledged packet sequence number. When this sequence number is acknowledged, it returns to the congestion avoidance state.
- Tries to deal with multiple packet losses as a single congestion event.

*Vegas*
- A proactive method to replace the reactive solutions.
- Vegas is based on RTT measurements. It anticipates losses and adjusts the congestion window accordingly.

*Westwood*
- A modification of NewReno.
- Substantially better in error-prone networks, such as wireless networks.
- Replaces the blind Reno's congestion control with a heuristic procedure.

*CUBIC*
- Designed for long, fat networks.

**What were the main hacks used because of HTTP/1.1?**

*Domain sharding*

Splits site resources across different origins, in order to allow the client to
open more than six TCP connections.

*Concatenating files (JavaScript, CSS)*

This caused less modular code and expensive cache invalidations when anything
changed. It also slowed down execution, as the browser had to wait for the
whole file to be downloaded.

Content prioritization introduced in HTTP/2 helps alleviate the need for this.

*Image spriting*

Preprocessing was required to make up the sprites. Also, the whole sprite
bitmap had to be decoded at once, which was heavy on the client.

*Resource inlining*

Prevents resources from being cached. Pays the overhead of Base64 encoding.

This is addressed by HTTP/2 through server push.

**Talk about the binary frame and header compression.**

Binary framing was introduced in HTTP/2.

All binary frames have an 8-byte header with the fields length (16 bits), type (8 bits), flags (8 bits), 1 reserved bit, and the stream identifier (31 bits).

HTTP/2 performs header compression, in which both client and server maintain
"header tables". Therefore, only changes to the headers have to be sent through
the network.

**What are the three main multimedia classes studied?**

*Streaming stored audio video*

Can leverage large buffers and CDNs. The most resilient to latency.

*Streaming live audio or video*

More sensitive to latency than stored video.

*Conversational audio or video over IP*

The most sensitive to network oscillations, as the latency has to be kept low.

**Why client-side buffering is important?**

The client wants to have continuous playout of video. However, the network
delay and its variation (jitter) make the time of arrival of frames variable.
Client-side buffering alleviates this problem by storing more video than the
barely minimum needed for continuous playout.

**Why CDNs matter?**

CDNs distribute content to cache servers located close to users, resulting in
fast, reliable applications and Web services for the users.

More specifically, they maintain multiple points of presence with clusters of
surrogate servers that store copies of identical content.

**How is the CDN node selected?**

The CDN node may be selected as the one that is the fewest hops or the least number of network seconds away from the requesting client.
It may also be the one with the highest availability in terms of server performance, so as to optimize delivery across local networks.
It may even be optimized for cost, and the locations that are least expensive may be chosen instead.
These two goals tend to align as the cheapest is usually the closest location.

**What is content outsourcing?**

Content outsourcing is the operation of moving data into a CDN.

Three common content outsourcing practices are the following.

+ *Cooperative push-based*. Content is proactively pushed from the original server into the CDN servers.
+ *Uncooperative pull-based*. Client requests are redirected through DNS redirection or URL rewriting to their closest surrogate server. If a cache miss occurs, the CDN server will pull from the origin server.
+ *Cooperative pull-based*. Client requests are redirected through DNS redirection or URL rewriting to their closest surrogate server. The key difference is that the CDN servers will cooperate so that in case of a miss they will first reach out to other CDN servers.

**What are the most prevalent CDN content selection algorithms?**

Typically, Web content is grouped based on either correlation or access frequency and then replicated in units of content clusters.
Content clustering can be based on user session statistics or on the site topology.


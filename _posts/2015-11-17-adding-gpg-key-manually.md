---
layout: post
title: "Adding a GPG Key Manually"
---

I was trying to install MongoDB 3.0 in my production machine and in order to be
able to do that via `apt-get` I needed to import the MongoDB GPG public key.

It went wrong. It went really wrong.

After a **huge** delay at

    gpg: requesting key 7F0CEB10 from hkp server keyserver.ubuntu.com

I would get

    gpg: keyserver timed out
    gpg: keyserver receive failed: keyserver error

The first solutions I found on the internet for this problem were modifying
other commands to look like mine. So I already had the "best command".

After some more Googling I found that I could grab the key manually and add it
without a request to a server.

So I tried and got [the key]({{ site.baseurl }}/assets/10gen-gpg-key.asc).

Ran

    sudo apt-key add 10gen-gpg-key.asc

And the shell told me

    OK

That was it. I decided to post about this so that if you find yourself in a
similar scenario (cannot get keys via the command line), you have an idea of
how to solve the problem. It also serves as a future reference to me, as
StackOverflow didn't do it this time.

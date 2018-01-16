---
layout: post
title: "Recovering Deleted Files"
---

This post is specific to ext3 and ext4 partitions.

Yesterday I accidentally invoked `bunzip2` without the `--keep` flag.  This
made me lose the original, compressed file. It would be complicated to get it
back, therefore I used to `extundelete` to recover it. This post gives an
example of the usage of `extundelete`.

First of all, I needed to have the partition mount as read-only, but I was
using it to run my operating system, so I had to reboot and start from a live
image.

Once I had it running, getting `extundelete` was easy

    sudo dnf install extundelete

After that, I simply invoked

    sudo extundelete --recover-file <path-to-file> <device>

In my case,

    sudo extundelete --recover-file mg/wiki/dump.bz2 /dev/sda7

Finally, I copied the recovered file (found on a `RECOVERED_FILES` directory)
to its final destination with `cp` and was done with it.

Hopefully this will be helpful to you someday.

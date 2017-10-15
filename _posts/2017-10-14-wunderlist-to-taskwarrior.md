---
layout: post
title: Wunderlist to Taskwarrior
---

# Description

Wunderlist to Taskwarrior is an application that fetches your tasks from
Wunderlist and inserts them into Taskwarrior. It can be regularly ran by the
operating system to keep Taskwarrior up-to-date.

## Why I Made This

As I cannot update Taskwarrior when I am not near one of my computers I needed a
way to update Taskwarrior while on the road. The solution I found uses
Wunderlist as an intermediate. I already used Wunderlist for simple lists such
as the weekly groceries but I greatly prefer Taskwarrior over it, so I still use
Taskwarrior when I am at my computer.

## Relevant Features

+ **Selective Syncrhonization.** Lists starting with "!" are never synchronized.
+ **Data Safety.** All communication is done via HTTPS.
+ **Persistence.** SQLite is used to keep track of what has been synchronized.

I had to decide between a continuous process which would update Taskwarrior or a
utility application that would be scheduled to run regularly. I opted for the
latter as the application initialization and termination are not so expensive.
Currently, I've been running it every minute on one of my computers.

# The Code

Wunderlist to Taskwarrior was written in Haskell using Stack so it should be
easy enough to get a build for your own computer.

[This is the GitHub repository](https://github.com/mafagafogigante/wunderlist-to-taskwarrior).

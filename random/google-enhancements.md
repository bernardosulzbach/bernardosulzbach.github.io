---
layout: page
title: Google enhancements
tags: [random]
---

This page contains some enhancements to Google search.

# Remove "People also search for" from popping up

Create the following rule for `google.com` in [Stylus](https://chrome.google.com/webstore/detail/stylus/clngdbkpkpeebahjckkjfobafhncgmne/).

```css
div[data-base-uri="/search"] {
    display: none !important;
    height: 0px !important;
    width: 0px !important;
}

.exp-outline {
    display: none !important;
}
```

Last tested using google.com from Brazil, in 2019-05-28.

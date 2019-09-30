---
layout: page
title: Google enhancements
tags: [random]
---

This page contains some enhancements to Google search.

# Remove "People also search for" from popping up

This patch removes the annoying animation that Google gives you when you go back to the search results.

This issue has been described in [this Stack Exchange question](https://webapps.stackexchange.com/questions/115038/how-to-stop-googles-people-also-search-for).

Create the following rule for `google.com` in [Stylus](https://chrome.google.com/webstore/detail/stylus/clngdbkpkpeebahjckkjfobafhncgmne/).

```css
div[data-base-uri^="/search"] {
    display: none !important;
    height: 0px !important;
    width: 0px !important;
}

.exp-outline {
    display: none !important;
}
```

## Version history

In 2019-05-28, the original patch was written.

In 2019-09-30, because of an update to Google Search, an update was required.

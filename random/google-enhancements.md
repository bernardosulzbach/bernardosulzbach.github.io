---
layout: page
title: Google enhancements
tags: [random]
---

This page contains some enhancements to Google search.

# Remove "People also search for" from popping up

This patch removes the annoying animation that Google gives you when you go back to the search results.

This issue has been described in [this Stack Exchange question](https://webapps.stackexchange.com/questions/115038/how-to-stop-googles-people-also-search-for).

Create the following rule for `google.com` in [Stylus](https://chrome.google.com/webstore/detail/stylus/clngdbkpkpeebahjckkjfobafhncgmne/) or any other extension that allows for CSS injection.

```css
div[id^='eob'] {
    display: none !important;
    height: 0px !important;
    width: 0px !important;
}

.exp-outline {
    display: none !important;
}
```

## Version history

### 2019-05-28

The original rule was written.

### 2019-09-30

Because of an update to Google Search, an update of the rule was required.

### 2020-05-29

Because of an update to Google Search, an update of the rule was required.

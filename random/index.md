---
layout: page
title: Random
tags: [sidebar]
---

All page-based content that is too scattered to get its own tree falls into
random.

This page is the index of all random pages, sorted alphabetically.

<ul>
{% assign pages = site.pages | sort: 'title' %}
{% for page in pages %}
  {% for tag in page.tags %}
    {% if tag == "random" %}
      <li><a href="{{ site.baseurl }}{{ page.url }}">{{ page.title }}</a></li>
    {% endif %}
  {% endfor %}
{% endfor %}
</ul>

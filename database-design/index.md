---
layout: page
title: Database Design
tags: [sidebar]
---

Below is a list of the pages about database design on my website.

<ul>
{% assign pages = site.pages | sort: 'title' %}
{% for page in pages %}
  {% for tag in page.tags %} 
    {% if tag == "database-design" %}
      <li><a href="{{ site.baseurl }}{{ page.url }}">{{ page.title }}</a></li>
    {% endif %}
  {% endfor %}
{% endfor %}
</ul>

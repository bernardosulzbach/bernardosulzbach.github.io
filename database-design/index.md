---
layout: page
title: Database Design
tags: [sidebar]
---

Below is a list of the pages about database design on my website.

<ul>
{% for page in (site.pages | sort) %}
  {% for tag in page.tags %} 
    {% if tag == "database-design" %}
      <li><a href="{{ site.baseurl }}{{ page.url }}">{{ page.title }}</a></li>
    {% endif %}
  {% endfor %}
{% endfor %}
</ul>

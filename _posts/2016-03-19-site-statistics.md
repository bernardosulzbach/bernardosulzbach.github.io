---
layout: post
title: Site Statistics
---

This is my first variable post. By variable post I mean a post that **might
change at every recompilation of the website**.

I had this idea when thinking about getting a word count of the project.
Instead of just computing the word count for myself, I decided to make it into
an always up-to-date blog post.

{% assign post_word_count = 0 %}
{% for post in site.posts %}
  {% capture post_word_count %}
    {{ post.content | number_of_words | plus: post_word_count }}
  {% endcapture %}
{% endfor %}

{% assign page_word_count = 0 %}
{% for page in site.pages %}
  {% capture page_word_count %}
    {{ page.content | number_of_words | plus: page_word_count }}
  {% endcapture %}
{% endfor %}

{% capture word_count %}{{ post_word_count | plus: page_word_count }}{% endcapture %}

{% assign post_count = site.posts | size %}
{% assign page_count = site.pages | size %}

# Basic statistics

|Word count               | {{ word_count }}  |
|Post count               | {{ post_count }}                               |
|Page count               | {{ page_count }}                               |
|Mean word count per post | {{ post_word_count | divided_by: post_count }} |
|Mean word count per page | {{ page_word_count | divided_by: page_count }} |

# Extrapolated statistics

The average English reader would take {{ word_count | divided_by: 300.0 | ceil
}} minutes to read the whole website.

The website is equivalent to {{ word_count | divided_by: 65000.0 | round: 2 }} novels.

---
layout: page
title: Shaving creams
description: A comparison between some of the most popular shaving creams in Brazil.
tags: [random]
---

In this page I will outline the most popular shaving creams in Brazil and their composition in order to analyze what they have in common and what are their exclusive ingredients.
The code used for the analysis is also provided.

## The analyzed shaving creams

These are the products used in the analysis, the data is also available in JSON format, which was used for the analysis.

### "NIVEA MEN Sensitive"

Aqua, Glycerin, Myristic Acid, Palmitic Acid, Stearic Acid, Potassium Hydroxide, Glyceryl Stearate, PEG-8, Cera Alba, Parfum, Maris Sal, Chamomilla Recutita Flower Extract, Oleic Acid, Maltodextrin, Acrylates Copolymer, Sodium Methyl Cocoyl Taurate, Arachidic Acid, Sodium Lauryl Sulfate, Trisodium EDTA.

[Web page](https://www.nivea.com.br/produtos/nivea-men-sensitive-creme-de-barbear-2-em-1-40059003284720033.html). Accessed on 2019-08-02.

### "BOZZANO Hidratação"

Aqua\*, Stearic Acid, Glycerin\*, Potassium Hydroxide, Orbignya Speciosa Kernel Oil, Parfum, Boric Acid, Aloe Barbadensis Leaf Extract, Sodium Hydroxide, Lanolin, Cellulose Gum, Lanolin Oil, Enteromorpha Compressa Extract\*, Hydrolyzed Caesalpinia Spinosa Gum\*, Caesalpinia Spinosa Gum\*, Rheum Rhaponticum Root Extract\*, Phenoxyethanol\*, Sodium Benzoate\*, Potassium Sorbate\*, Linalool, Limonene, Hexyl Cinnamal.

[Web page](http://www.bozzano.com.br/cremes.php#Hidrata%C3%A7%C3%A3o). Accessed on 2019-08-02.

### "BOZZANO Refrescante"

Aqua\*, Stearic Acid, Glycerin\*, Potassium Hydroxide, Orbignya Speciosa Kernel Oil, Parfum, Boric Acid, Menthol, Sodium Hydroxide, Lanolin, Cellulose Gum, Lanolin Oil, Enteromorpha Compressa Extract\*, Hydrolyzed Caesalpinia Spinosa Gum\*, Caesalpinia Spinosa Gum\*, Rheum Rhaponticum Root Extract\*, Phenoxyethanol\*, Sodium Benzoate\*, Potassium Sorbate\*, Linalool, Limonene, Hexyl Cinnamal.

[Web page](http://www.bozzano.com.br/cremes.php#Refrescante). Accessed on 2019-08-02.

### "BOZZANO Pele Sensível"

Aqua\*, Stearic Acid, Glycerin\*, Potassium Hydroxide, Orbignya Speciosa Kernel Oil, Boric Acid, Helianthus Annuus Seed Oil, Menthol, Sodium Hydroxide, Lanolin, Cellulose Gum, Camphor, Thymol, Lanolin Oil, Enteromorpha Compressa Extract\*, Eugenia Caryophyllus Flower Extract, Eucalyptus Globulus Leaf Extract, Mentha Piperita Leaf Extract, Hydrolyzed Caesalpinia Spinosa Gum\*, Caesalpinia Spinosa Gum\*, Rheum Rhaponticum Root Extract\*, Phenoxyethanol\*, Sodium Benzoate\*, Potassium Sorbate\*, BHT, Ascorbyl Palmitate.

[Web page](http://www.bozzano.com.br/cremes.php#PeleSens%C3%ADvel). Accessed on 2019-08-02.

### Data in a JSON file

The [data is available in this JSON file]({{ site.base_url }}/assets/shaving-creams/data.json).

## Analysis

There are 45 different ingredients in the above products.

### The common ingredients

Four ingredients are common all across the board:
+ Glycerin
+ Potassium Hydroxide
+ Stearic Acid
+ Aqua

### The exclusive ingredients

The following lists show the ingredients which only appear in a single product.

#### Exclusive to "NIVEA MEN Sensitive" (14)

+ Myristic Acid
+ Palmitic Acid
+ Glyceryl Stearate
+ PEG-8
+ Cera Alba
+ Maris Sal
+ Chamomilla Recutita Flower Extract
+ Oleic Acid
+ Maltodextrin
+ Acrylates Copolymer
+ Sodium Methyl Cocoyl Taurate
+ Arachidic Acid
+ Sodium Lauryl Sulfate
+ Trisodium EDTA

#### Exclusive to "BOZZANO Hidratação" (1)

+ Aloe Barbadensis Leaf Extract

#### Exclusive to "BOZZANO Refrescante" (0)

None.

#### Exclusive to "BOZZANO Pele Sensível" (8)

+ Helianthus Annuus Seed Oil
+ Camphor
+ Thymol
+ Eugenia Caryophyllus Flower Extract
+ Eucalyptus Globulus Leaf Extract
+ Mentha Piperita Leaf Extract
+ BHT
+ Ascorbyl Palmitate

### Code to perform the analysis

The code used to perform the analysis is available below.

```python
{% include shaving-creams/analyze.py %}
```

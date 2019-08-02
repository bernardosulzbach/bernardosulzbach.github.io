import collections
import json
import sys


def make_ingredient_list(ingredient_string):
    ingredients = ingredient_string.strip('.').split(',')
    ingredients = [ingredient.strip().strip('*') for ingredient in ingredients]
    return ingredients


def print_ingredient_list(list_name: str, ingredient_list: list):
    print('"{}" ({})'.format(list_name, len(ingredient_list)))
    for ingredient in ingredient_list:
        print('  {}'.format(ingredient))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Provide just the path to the JSON data file.')
        exit(1)
    products = {}
    with open(sys.argv[1]) as data_file_handle:
        data = json.load(data_file_handle)
        for key in data:
            products.update({key: data[key]})
    for product_name in products:
        products[product_name] = make_ingredient_list(products[product_name])
    ingredient_frequency = collections.Counter()
    for product_name in products:
        ingredient_frequency.update(products[product_name])
    print('Found {} different ingredients.'.format(len(ingredient_frequency)))
    common_ingredients = set()
    for ingredient in ingredient_frequency:
        if ingredient_frequency[ingredient] == len(products):
            common_ingredients.add(ingredient)
    print_ingredient_list('Common ingredients', list(common_ingredients))
    for product_name in products:
        exclusive = []
        for ingredient in products[product_name]:
            if ingredient_frequency[ingredient] == 1:
                exclusive.append(ingredient)
        print_ingredient_list('Exclusive to {}'.format(product_name), exclusive)

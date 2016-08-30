import math
import time

import lexicographic_permutations
import heaps_algorithm_recursive
import heaps_algorithm_non_recursive

INTEGER_COUNT = 10
STRING_COUNT = 10
STRING_LENGTH = 100


def generate_integers():
    return list(range(INTEGER_COUNT))


def generate_strings():
    strings = []
    for i in range(STRING_COUNT):
        strings.append('A' * (STRING_LENGTH - 1) + chr(ord('A') + i))
    return strings


def timed(function):
    def function_wrapper(*args):
        start = time.clock()
        function(*args)
        delta = time.clock() - start
        return delta

    return function_wrapper


@timed
def time_lexicographic(values):
    for _ in range(math.factorial(len(values))):
        lexicographic_permutations.next_permutation(values)


@timed
def time_heaps_recursive(values):
    for _ in heaps_algorithm_recursive.permutations(values):
        pass


@timed
def time_heaps_non_recursive(values):
    for _ in heaps_algorithm_non_recursive.permutations(values):
        pass


def run_benchmarks(format_string, make_data):
    data = make_data()
    lexicographic_time = time_lexicographic(make_data())
    print(format_string.format("Lexicographic", len(data), lexicographic_time))
    recursive_heaps_time = time_heaps_recursive(make_data())
    print(format_string.format("Recursive Heap's", len(data), recursive_heaps_time))
    non_recursive_heaps_time = time_heaps_non_recursive(make_data())
    print(format_string.format("Non-recursive Heap's", len(data), non_recursive_heaps_time))


if __name__ == '__main__':
    run_benchmarks("{} with {} integers took {:.2f} seconds.", generate_integers)
    run_benchmarks("{} with {} strings took {:.2f} seconds.", generate_strings)

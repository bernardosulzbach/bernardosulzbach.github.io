def swap(elements, i, j):
    elements[i], elements[j] = elements[j], elements[i]


def generate_permutations(elements, n):
    if n == 0:
        yield elements
    else:
        for i in range(n - 1):
            # Generate permutations with the last element fixed.
            yield from generate_permutations(elements, n - 1)
            # Swap the last element.
            if i % 2 == 0:
                swap(elements, i, n - 1)
            else:
                swap(elements, 0, n - 1)
        # Generate the last permutations after the final swap.
        yield from generate_permutations(elements, n - 1)


def permutations(elements):
    yield from generate_permutations(elements, len(elements))

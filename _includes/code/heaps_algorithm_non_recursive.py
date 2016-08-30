def swap(elements, i, j):
    elements[i], elements[j] = elements[j], elements[i]


def generate_permutations(elements, n):
    # As by Robert Sedgewick in Permutation Generation Methods
    c = [0] * n
    yield elements
    i = 0
    while i < n:
        if c[i] < i:
            if i % 2 == 0:
                swap(elements, 0, i)
            else:
                swap(elements, c[i], i)
            yield elements
            c[i] += 1
            i = 0
        else:
            c[i] = 0
            i += 1


def permutations(elements):
    return generate_permutations(elements, len(elements))

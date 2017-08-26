def swap(elements, i, j):
    elements[i], elements[j] = elements[j], elements[i]


def reverse(elements, i, j):
    for offset in range((j - i + 1) // 2):
        swap(elements, i + offset, j - offset)


def next_permutation(elements):
    last_index = len(elements) - 1
    if last_index < 1:
        return

    i = last_index - 1
    while i >= 0 and not elements[i] < elements[i + 1]:
        i -= 1

    # If there is no greater permutation, return to the first one.
    if i < 0:
        reverse(elements, 0, last_index)
    else:
        j = last_index
        while j > i + 1 and not elements[j] > elements[i]:
            j -= 1

        swap(elements, i, j)
        reverse(elements, i + 1, last_index)
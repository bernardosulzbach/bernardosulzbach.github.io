# A function to evaluate Levenshtein distance.
#
# Licensed under the BSD 3-Clause license.

def levenshtein(a, b):
    """
    Evaluates the Levenshtein distance between two strings.
    """
    if len(a) < len(b):
        a, b = b, a
    if len(b) == 0:  # len(a) >= len(b)
        return len(a)
    a = ' ' + a
    b = ' ' + b
    d = {}
    for i in range(len(a)):
        d[i, 0] = i
    for j in range(len(b)):
        d[0, j] = j
    for i in range(1, len(a)):
        for j in range(1, len(b)):
            if a[i] == b[j]:
                # Got the same character
                # Just use the answer to the prefix
                d[i, j] = d[i - 1, j - 1]
            else:
                # Not the same character
                # Use the smallest of diagonal, above or left
                # And add 1 to account for the extra modification needed
                d[i, j] = min(d[i - 1, j - 1], d[i, j - 1], d[i - 1, j]) + 1
    return d[len(a) - 1, len(b) - 1]


if __name__ == '__main__':
    assert levenshtein('', '') == 0
    assert levenshtein('', 'a') == 1
    assert levenshtein('a', 'a') == 0
    assert levenshtein('a', 'b') == 1
    assert levenshtein('abc', 'cab') == 2
    assert levenshtein('there could be an answer', 'answer') == 18

def cross(a, b, o):
    x = (a[0] - o[0]) * (b[1] - o[1])
    y = (a[1] - o[1]) * (b[0] - o[0])
    return x - y


def convex_hull(points):
    points = list(sorted(points))
    upper = []
    for p in points:
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) >= 0:
            upper.pop()
        upper.append(p)
    lower = []
    for p in points[::-1]:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) >= 0:
            lower.pop()
        lower.append(p)
    hull = upper
    hull.pop()
    hull.extend(lower)
    hull.pop()
    return hull

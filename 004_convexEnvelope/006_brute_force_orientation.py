def convex_hull(points):
    n = len(points)
    if n < 3:
        return []
    hull = []
    l = 0
    for i in range(1, n):
        if points[i][0] < points[l][0]:
            l = i
    p = l
    q = 0
    while True:
        hull.append(points[p])
        q = (p+1) % n
        for i in range(n):
            if (orientation(points[p], points[i], points[q]) == 2):
                q = i
        p = q
        if p == l:
            break
    return hull


def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (5, 5)]
print(convex_hull(points))
# output [(0,0), (5,5), (4,4), (3,3), (2,2), (1,1)]

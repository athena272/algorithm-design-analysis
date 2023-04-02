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
            cross = (points[i][1] - points[p][1]) * (points[q][0] - points[p][0]) - \
                (points[q][1] - points[p][1]) * (points[i][0] - points[p][0])
            if cross > 0:
                q = i
        p = q
        if p == l:
            break
    return hull


points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (5, 5)]
print(convex_hull(points))
# output [(0,0), (5,5), (4,4), (3,3), (2,2), (1,1)]

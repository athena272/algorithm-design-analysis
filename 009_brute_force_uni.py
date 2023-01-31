def convex_envelope_brute_force(points):
    n = len(points)
    for i in range(n):
        # a = y2 - y1 
        a = points[i + 1][1] - points[i][1]
        # b = x1 - x2
        b = points[i][0] - points[i + 1][0]
        # c = x1y2 - y1x2
        

a = [(0, 0), (1, 1)]

print(a[1][1])
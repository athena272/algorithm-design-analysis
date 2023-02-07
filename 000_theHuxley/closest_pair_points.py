import math


def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)


def closest_pair(points):
    n = len(points)
    min_dist = float("inf")
    for i in range(n):
        for j in range(i+1, n):
            dist_ij = dist(points[i][0], points[i][1],
                           points[j][0], points[j][1])
            if dist_ij < min_dist:
                min_dist = dist_ij
    return min_dist


while True:
    n = int(input().strip())
    if n == 0:
        break
    points = []
    for i in range(n):
        x, y = map(float, input().strip().split())
        points.append((x, y))
    min_dist = closest_pair(points)
    if min_dist >= 10000:
        print("INFINITY")
    else:
        print("%.4f" % min_dist)

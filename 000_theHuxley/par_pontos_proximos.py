# This code sorts the points based on their x-coordinate, and then uses the
# closest_pair_helper function to find the minimum distance between any two points.
# closest_pair_helper function uses divide and conquer to solve the problem, and the
# closest_pair function wraps the closest_pair_helper function and sorts the points
# before calling it. The minimum distance between any two points is returned by the
# closest_pair function and rounded to 4 decimal places.


import math


def dist(p1, p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)


def closest_pair_helper(points):
    if len(points) <= 3:
        return min([dist(points[i], points[j]) for i in range(len(points)) for j in range(i+1, len(points))])

    mid = len(points)//2
    dl = closest_pair_helper(points[:mid])
    dr = closest_pair_helper(points[mid:])
    d = min(dl, dr)

    strip = [p for p in points if abs(p[0]-points[mid][0]) < d]
    strip.sort(key=lambda x: x[1])

    for i in range(len(strip)):
        for j in range(i+1, min(i+7, len(strip))):
            d = min(d, dist(strip[i], strip[j]))

    return d


def closest_pair(points):
    points.sort(key=lambda x: x[0])
    return closest_pair_helper(points)


n = int(input().strip())
points = [tuple(map(int, input().strip().split())) for _ in range(n)]
print("%.4f" % closest_pair(points))

# Explanation:

# The function dist calculates the Euclidean distance between two points (x1, y1) and (x2, y2).
# The function closest_pair takes a list of points as input and calculates the minimum distance between any two points using nested for loops.
# The main loop continues to read the input until it encounters a case with n = 0, which signals the end of the input.
# For each case, the input points are stored in a list, and the minimum distance between any two points is calculated by calling the closest_pair function.
# If the minimum distance is greater than or equal to 10000, "INFINITY" is printed. Otherwise, the minimum distance is printed with 4 decimal places.

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

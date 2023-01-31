# This algorithm uses a stack data structure to efficiently maintain the Convex Envelope while processing the points in a specific order. The time complexity of Graham's scan algorithm is O(nlogn) where n is the number of points.

# Compared to the brute-force algorithm, both Graham's scan and Jarvis march algorithms are much more efficient and can handle large sets of points efficiently. These algorithms are widely used in computer graphics, computer vision, and computational geometry applications.

from typing import List
import math


def line():
    print("=+=" * 25)


def orientation(p: List[int], q: List[int], r: List[int]) -> int:
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def convex_envelope_graham(points: List[List[int]]) -> List[List[int]]:
    n = len(points)
    if n < 3:
        return points

    # Find the bottom-most point
    ymin = points[0][1]
    minn = 0
    for i in range(1, n):
        y = points[i][1]
        if y < ymin or (ymin == y and points[i][0] < points[minn][0]):
            ymin = points[i][1]
            minn = i

    # Swap the bottom-most point with the first point
    points[0], points[minn] = points[minn], points[0]

    # Sort the points by polar angle with the first point
    points = sorted(points, key=lambda p: math.atan2(
        p[1] - points[0][1], p[0] - points[0][0]))

    m = 1
    for i in range(1, n):
        while i < n - 1 and orientation(points[0], points[i], points[i + 1]) == 0:
            i += 1
        points[m] = points[i]
        m += 1

    if m < 3:
        return []

    hull = [points[0], points[1], points[2]]
    for i in range(3, m):
        while len(hull) > 1 and orientation(hull[-2], hull[-1], points[i]) != 2:
            hull.pop()
        hull.append(points[i])

    return hull


# Example 0
points = [(0,0), (1,1), (2,2), (3,3), (4,4)]
print(convex_envelope_graham(points))
# [(0,0), (4,4), (3,3), (2,2), (1,1)]
line()

# Example 1
points = [(0, 0), (1, 0), (1, 1), (0, 1), (0.5, 0.5)]
print(convex_envelope_graham(points))
# [(0, 0), (1, 0), (1, 1), (0, 1), (0, 0)]
line()

# Example 2
points = [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]
print(convex_envelope_graham(points))
# [(1, 2), (5, 6), (5, 6), (1, 2), (1, 2)]
line()

# Example 3
points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4)]
print(convex_envelope_graham(points))
# []
line()

# Example 4
points = [(0, 0), (1, 2), (2, 4), (3, 6), (4, 8)]
print(convex_envelope_graham(points))
# []

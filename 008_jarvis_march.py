# Another popular algorithm for finding the Convex Envelope is the Jarvis march (or Gift wrapping) algorithm. This algorithm starts with an arbitrary point on the Convex Envelope, and it iteratively selects the next point on the Convex Envelope by computing the orientation of the line segments connecting the current point to all other points. The time complexity of Jarvis march algorithm is O(nh), where n is the number of points and h is the number of points on the Convex Envelope.

# Compared to the brute-force algorithm, both Graham's scan and Jarvis march algorithms are much more efficient and can handle large sets of points efficiently. These algorithms are widely used in computer graphics, computer vision, and computational geometry applications.

from typing import List


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


def next_to_top(S: List[List[int]]) -> List[int]:
    return S[-2]


def convex_envelope_jarvis(points: List[List[int]]) -> List[List[int]]:
    n = len(points)
    if n < 3:
        return points

    l = 0
    for i in range(1, n):
        if points[i][0] < points[l][0]:
            l = i


points = [(0, 0), (1, 0), (1, 1), (0, 1), (0.5, 0.5)]
print(convex_envelope_jarvis(points))
# [(0, 0), (1, 0), (1, 1), (0, 1), (0, 0)]
line()

# Example 2
points = [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]
print(convex_envelope_jarvis(points))
# [(1, 2), (5, 6), (5, 6), (1, 2), (1, 2)]
line()

# Example 3
points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4)]
print(convex_envelope_jarvis(points))
# []
line()

# Example 4
points = [(0, 0), (1, 2), (2, 4), (3, 6), (4, 8)]
print(convex_envelope_jarvis(points))
# []


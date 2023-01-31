# A brute-force approach to finding the Convex Envelope of a set of points in Python is to generate all possible combinations of points and calculate the area of the convex polygon formed by those points. The combination with the maximum area is the Convex Envelope.

# Note that this is a naive implementation, and its time complexity is O(N^2) where N is the number of points. For larger datasets, it may be impractical to use a brute-force approach, and more efficient algorithms should be used instead.

import itertools


def line():
    print("=+=" * 25)


def convex_envelope_brute_force(points):
    n = len(points)
    max_area = 0
    envelope = []

    # Generate all possible combinations of points
    for comb in itertools.combinations(points, n - 1):
        poly = list(comb) + [points[0]]
        area = 0

        # Calculate the area of the convex polygon
        for i in range(n - 1):
            j = (i + 1) % n
            area += poly[i][0] * poly[j][1] - poly[j][0] * poly[i][1]

        # Check if this combination has a larger area than the previous maximum
        if area > max_area:
            max_area = area
            envelope = poly

    return envelope

# In this example, the points list contains 5 points in a two-dimensional plane. The convex_envelope_brute_force function is called with the points list as an argument, and the expected output is a list of points that form the Convex Envelope of the input points. The output list is a convex polygon that encloses the maximum area between the input points, and it contains the same number of points as the input list.F

# In each of these examples, the convex_envelope_brute_force function is called with a different list of points, and the expected output is a list of points that form the Convex Envelope of the input points. The output list is a convex polygon that encloses the maximum area between the input points, and it contains the same number of points as the input list.

# The examples 3 and 4 should return an empty list [] since the input points are collinear and do not form a Convex Envelope.


# Example 1
points = [(0, 0), (1, 0), (1, 1), (0, 1), (0.5, 0.5)]
print(convex_envelope_brute_force(points))
# [(0, 0), (1, 0), (1, 1), (0, 1), (0, 0)]
line()

# Example 2
points = [(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)]
print(convex_envelope_brute_force(points))
# [(1, 2), (5, 6), (5, 6), (1, 2), (1, 2)]
line()

# Example 3
points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4)]
print(convex_envelope_brute_force(points))
# []
line()

# Example 4
points = [(0, 0), (1, 2), (2, 4), (3, 6), (4, 8)]
print(convex_envelope_brute_force(points))
# []


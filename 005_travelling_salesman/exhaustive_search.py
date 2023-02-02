import itertools


def distance(a, b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5

def tsp_brute_force(points):

    # sets the initial value of the variable to positive infinity.
    best_distance = float("inf")
    best_tour = []
    for tour in itertools.permutations(points):
        current_distance = 0
        for i in range(len(tour) - 1):
            current_distance += distance(tour[i], tour[i + 1])
        current_distance += distance(tour[0], tour[-1])
        if current_distance < best_distance:
            best_distance = current_distance
            best_tour = tour
    return best_distance, best_tour


points = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (5, 5)]
print(tsp_brute_force(points))

# from itertools import permutations: This line imports the permutations function from the itertools module in Python. This function returns all the permutations of a given iterable object.

# import math: This line imports the math module, which provides mathematical functions, including the square root function used later in the code.

# def distance(city1, city2): This function calculates the Euclidean distance between two cities represented as tuples of their x and y coordinates.

# def traveling_salesman(cities): This function implements the exhaustive search algorithm for the traveling salesman problem. It takes a list of cities as input and returns the minimum distance and the corresponding order of visiting cities.

# best_distance = float("inf"): This line initializes the variable best_distance with positive infinity, which is used to keep track of the minimum distance found so far.

# for permutation in permutations(cities):: This loop iterates over all permutations of the input cities.

# distance_perm = 0: This line initializes the variable distance_perm with 0, which is used to keep track of the total distance for the current permutation.

# for i in range(len(permutation) - 1):: This inner loop iterates over all the adjacent pairs of cities in the current permutation.

# distance_perm += distance(permutation[i], permutation[i + 1]): This line adds the distance between the current pair of cities to the total distance for the current permutation.

# if distance_perm < best_distance:: This line checks if the total distance for the current permutation is less than the minimum distance found so far.

# best_distance = distance_perm: If the total distance for the current permutation is less than the minimum distance found so far, this line updates the value of best_distance.

# best_permutation = permutation: This line updates the value of best_permutation with the current permutation if the total distance for the current permutation is less than the minimum distance found so far.

# return best_distance, best_permutation: This line returns the minimum distance and
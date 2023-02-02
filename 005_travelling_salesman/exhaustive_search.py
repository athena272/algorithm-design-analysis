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

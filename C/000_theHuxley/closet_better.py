import sys
import math

def distance(p1, p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def closest_pair(points):
    points = sorted(points, key=lambda x: x[0])
    n = len(points)
    min_dist = sys.float_info.max
    for i in range(n-1):
        for j in range(i+1, min(i+7, n)):
            dist = distance(points[i], points[j])
            if dist < min_dist:
                min_dist = dist
    return min_dist

def solve():
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
            print("{:.4f}".format(min_dist))


solve()

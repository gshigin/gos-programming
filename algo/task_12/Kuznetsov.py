from math import atan2, sqrt

def graham(points):
    min_point = min(points, key=lambda p: (p[1], p[0]))
    points.sort(key=lambda p: (atan2(p[1] - min_point[1], p[0] - min_point[0]), -p[1], p[0]))
    hull = [min_point]
    for p in points:
        while len(hull) > 1 and (hull[-1][0] - hull[-2][0]) * (p[1] - hull[-2][1]) <= (hull[-1][1] - hull[-2][1]) * (p[0] - hull[-2][0]):
            hull.pop()
        hull.append(p)
    return hull

def perimeter(hull):
    return sum(sqrt((hull[i][0] - hull[i-1][0])**2 + (hull[i][1] - hull[i-1][1])**2) for i in range(len(hull)))

def area(hull):
    return 0.5 * abs(sum(hull[i][0]*hull[i-1][1] - hull[i-1][0]*hull[i][1] for i in range(len(hull))))

# Пример использования:
points = [(4, 4), (1, 3), (3, 1), (2, 2), (5, 3)]
hull = graham(points)
print(perimeter(hull))
print(area(hull))

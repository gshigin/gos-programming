def generate_pascal_triangle(n, m):
    pascal_triangle = [[0] * m for i in range(n)]

    for i in range(n):
        pascal_triangle[i][0] = 1
    for j in range(m):
        pascal_triangle[0][j] = 1

    for i in range(1, n):
        for j in range(1, m):
            pascal_triangle[i][j] = pascal_triangle[i - 1][j] + pascal_triangle[i][j - 1]

    return pascal_triangle

n, m = map(int, input().split())

result = generate_pascal_triangle(n, m)
for row in result:
    print(*row)
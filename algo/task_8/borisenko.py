def prim(graph):
    n = len(graph)
    visited = [False] * n  # Массив для отслеживания посещенных вершин

    # Создаем список для хранения ключей (весов) вершин
    keys = [float('inf')] * n

    # Создаем список для хранения родительских вершин в остовном дереве
    parent = [-1] * n

    # Начинаем с первой вершины (можно выбрать любую)
    start_vertex = 3
    keys[start_vertex] = 0

    minimum_spanning_tree_weight = 0

    for k in range(n):
        # Находим вершину с минимальным ключом (минимальным весом)
        min_key = float('inf')
        min_vertex = -1
        for i in range(n):
            if not visited[i] and keys[i] < min_key:
                min_key = keys[i]
                min_vertex = i

        # Помечаем вершину как посещенную
        visited[min_vertex] = True
        minimum_spanning_tree_weight += min_key

        # Обновляем ключи соседних вершин
        for neighbor, weight in graph[min_vertex]:
            if not visited[neighbor] and weight < keys[neighbor]:
                keys[neighbor] = weight
                parent[neighbor] = min_vertex
    return minimum_spanning_tree_weight

# Ввод данных
n, m = map(int, input().split())
graph = [[] for _ in range(n)]

# Заполняем граф
for _ in range(m):
    b, e, w = map(int, input().split())
    graph[b - 1].append((e - 1, w))
    graph[e - 1].append((b - 1, w))

# Находим вес минимального остовного дерева
result = prim(graph)

# Вывод результата
print(result)
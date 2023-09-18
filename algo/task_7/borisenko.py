def bellman_ford(N, M, edges):
    INF = 30000  # Максимальное значение расстояния, используется как бесконечность

    distances = [INF] * N  # Создаем список расстояний с бесконечными значениями для каждой вершины
    distances[0] = 0  # Расстояние от вершины 1 до самой себя всегда равно 0
    print(distances)
    # Основной цикл алгоритма, выполняется N - 1 раз, где N - количество вершин
    for i in range(N - 1):
        # Проходим по всем ребрам графа
        for j in range(M):
            start, end, weight = edges[j]
            
            # Проверяем, существует ли путь от вершины start до end,
            # и если существует, проверяем, можно ли улучшить расстояние
            if distances[start - 1] != INF and distances[start - 1] + weight < distances[end - 1]:
                distances[end - 1] = distances[start - 1] + weight

    return distances

# Ввод данных
N, M = map(int, input().split())
edges = []
for _ in range(M):
    start, end, weight = map(int, input().split())
    edges.append((start, end, weight))

# Вычисление кратчайших расстояний
distances = bellman_ford(N, M, edges)

# Вывод результатов
for distance in distances:
    if distance == 30000:
        print(30000, end=' ')
    else:
        print(distance, end=' ')

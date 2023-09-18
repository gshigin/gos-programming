def shortest_path(graph, start, end):
    n = len(graph) 
    INF = float('inf') 

    dist = [INF] * n
    dist[start] = 0 
    visited = [False] * n   
    parent = [-1] * n 

    # Основной цикл алгоритма Дейкстры
    for ii in range(n):
        min_dist = INF
        u = -1
        for v in range(n):
            if not visited[v] and dist[v] < min_dist:
                min_dist = dist[v]
                u = v

        if u == -1:
            break  # Если не удалось найти непосещенную вершину с конечным расстоянием, выходим из цикла

        visited[u] = True  # Помечаем вершину как посещенную

        # Обновляем расстояния до смежных вершин через текущую вершину, при условии что смежную вершину еще не посетили, есть ребро 
        # и расстояние через вершину меньше чем уже сохраненное напрямую, либо начальное бескочненость
        for v in range(n):
            if not visited[v] and graph[u][v] != -1 and dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]
                parent[v] = u

    # Построение кратчайшего пути от конечной вершины к начальной
    if dist[end] == INF:
        return [-1]  # Если расстояние до конечной вершины осталось "бесконечность", путь не существует

    path = []
    u = end
    # Восстанавлиаем путь начиная с конечной вершины
    while u != -1:
        path.append(u)  # Добавляем вершину к пути (увеличиваем на 1, так как вершины нумеруются с 1)
        u = parent[u]  # Переходим к предыдущей вершине в пути

    path.reverse()  # Разворачиваем путь, чтобы он шел от начальной вершины к конечной

    return path

# Чтение входных данных
N, S, F = map(int, input().split())
graph = []
for _ in range(N):
    row = list(map(int, input().split()))
    graph.append(row)

# Поиск кратчайшего пути
result = shortest_path(graph, S-1, F-1)

# Вывод результата
for vertex in result:
    print(vertex+1, end=' ')
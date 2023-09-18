def dfs(graph, N, start):

    visited = [False] * N

    stack = [start]
    visited[start] = True
    count = 0

    while stack:
        vertex = stack.pop()
        count += 1

        for neighbor in range(len(graph)):
            if graph[vertex][neighbor] == 1 and not visited[neighbor]:
                stack.append(neighbor)
                visited[neighbor] = True
    return count

N, S = map(int, input().split())
graph = []

for _ in range(N):
    row = list(map(int, input().split()))
    graph.append(row)

component_size = dfs(graph, N, S - 1)

print(component_size)
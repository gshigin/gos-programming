def boruvka_mst(adj_matrix):
    n = len(adj_matrix)
    parent = list(range(n))
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    def union(x, y):
        root_x = find(x)
        root_y = find(y)
        if root_x != root_y:
            parent[root_y] = root_x
    mst_weight = 0
    while True:
        min_edge = [float('inf')] * n
        for i in range(n):
            for j in range(n):
                if find(i) != find(j) and adj_matrix[i][j] < min_edge[find(i)]:
                    min_edge[find(i)] = adj_matrix[i][j]
                    min_edge[find(j)] = adj_matrix[i][j]
        for i in range(n):
            if min_edge[i] < float('inf'):
                mst_weight += min_edge[i]
                union(i, [j for j in range(n) if adj_matrix[i][j] == min_edge[i]][0])
        if max(min_edge) == float('inf'):
            break
    return mst_weight

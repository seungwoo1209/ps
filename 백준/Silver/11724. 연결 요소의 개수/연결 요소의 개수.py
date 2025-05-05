import sys


def dfs(i, graph, visited):
    visited[i] = True
    for vertex in graph[i]:
        if not visited[vertex]:
            dfs(vertex, graph, visited)

def main():
    line = sys.stdin.readline
    N, M = map(int, line().split())
    graph = [[] for _ in range(N + 1)]
    visited = [False for _ in range(N + 1)]
    for _ in range(M):
        A, B = map(int, line().split())
        graph[A].append(B)
        graph[B].append(A)
    total_components = 0
    for i in range(1,N+1):
        if not visited[i]:
            dfs(i, graph, visited)
            total_components += 1
    print(total_components)

if __name__ == '__main__':
    main()

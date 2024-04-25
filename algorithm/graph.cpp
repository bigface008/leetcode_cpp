//
// Created by 汪喆昊 on 2024/4/13.
//

#include "leetcode_utils.hpp"

using namespace std;

// Dijjkstra 算法 如何查找图中两点之间的最短路径
// https://blog.csdn.net/YF_Li123/article/details/74090301
// 简单描述思路：
//

/*
 * origin: 起点
 * graph: 图的邻接矩阵
 * distances: 到每个点的最短距离
 * visited: 点是否被访问
 */
void dijkstra(int origin, const vector<vector<int>> &graph, vector<int> &distances, vector<bool> &visited) {
    fill(distances.begin(), distances.end(), INT_MAX);
    distances[origin] = 0;
    const int N = graph.size();
    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_dist = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && distances[j] < min_dist) {
                min_dist = distances[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        visited[u] = true;
        for (int v = 0; v < N; v++) {
            if (!visited[v] && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}

void d2(int origin, const vector<vector<int>> &graph, vector<int> &distances, vector<bool> &visited) {
    fill(distances.begin(), distances.end(), INT_MAX);
    distances[origin] = 0;
    const int N = graph.size();
    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_dist = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && distances[j] < min_dist) {
                min_dist = distances[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        visited[u] = true;
        for (int v = 0; v < N; v++) {
            int temp = graph[u][v] + distances[u];
            if (!visited[v] && distances[v] > temp) {
                distances[v] = temp;
            }
        }
    }
}

void test_dijkstra() {
    vector<vector<int>> graph = {
        {0, 1, 4, INT_MAX},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {INT_MAX, 5, 1, 0},
    };
    vector<int> distances(graph.size(), 0);
    vector<bool> visited(graph.size(), false);
    dijkstra(0, graph, distances, visited);
    fmt::println("dist {}", distances);

    fill(distances.begin(), distances.end(), 0);
    fill(visited.begin(), visited.end(), false);
    d2(0, graph, distances, visited);
    fmt::println("d2 {}", distances);
}

// 如何查找图中所有路径经过点的值的和的最大值？

int main() {
//    fmt::println("Dude");
//    int x = 0b1000;
//    fmt::println("x {}", x);
//    fmt::println("~x {}", ~x);
    test_dijkstra();
}

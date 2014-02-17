#include <queue>
#include <iostream>
void BFS(std::vector< std::vector<int> > &edges, std::vector<bool> &visited, int start) {
    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        std::cout << cur << std::endl;
        for (int i = 0; i < edges[cur].size(); i++) {
            if (edges[cur][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

void BFS(std::vector< std::vector<int> > &edges) {
    std::vector<bool> visited(edges.size(), false);
    for (int i = 0; i < edges.size(); i++)
        if (!visited[i])
            BFS(edges, visited, i);
}

int main() {
    std::vector< std::vector<int> > edges(8, std::vector<int>(8, 0));
    edges[0][1] = 1;
    edges[1][2] = 1;
    edges[2][0] = 1;
    edges[1][3] = 1;
    edges[2][3] = 1;
    edges[3][4] = 1;
    edges[4][3] = 1;
    edges[1][5] = 1;
    edges[5][4] = 1;
    edges[5][6] = 1;
    edges[6][5] = 1;
    edges[6][7] = 1;
    edges[4][7] = 1;
    edges[7][7] = 1;
    BFS(edges);
    return 0;
}

#include <stack>
#include <vector>
#include <iostream>
void DFS(std::vector< std::vector<int> > &edges, std::vector<bool> &visited, int start) {
    visited[start] = true;
    std::cout << start << std::endl;
    for (int i = 0; i < edges[start].size(); i++)
        if (edges[start][i] == 1 && !visited[i])
            DFS(edges, visited, i);
}

void DFS(std::vector< std::vector<int> > &edges) {
    std::vector<bool> visited(edges.size(), false);
    for (int i = 0; i < edges.size(); i++)
        if (!visited[i])
            DFS(edges, visited, i);
}

void DFSIterative(std::vector< std::vector<int> > &edges) {
    std::stack<int> stack;
    std::vector<bool> visited(edges.size(), false);
    for (int i = 0; i < edges.size(); i++) {
        if (!visited[i]) {
            stack.push(i);
            visited[i] = true;
            while (!stack.empty()) {
                int cur = stack.top();
                stack.pop();
                std::cout << cur << std::endl;
                for (int j = 0; j < edges[cur].size(); j++) {
                    if (edges[cur][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        stack.push(j);
                    }
                }
            }
        }
    }
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
    DFS(edges);
    DFSIterative(edges);
    return 0;
}

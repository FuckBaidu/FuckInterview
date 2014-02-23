#include <queue>
#include <iostream>
enum Color {
    Grey,
    Black,
    White,
};

void Partition(std::vector< std::vector<int> > &edges) {
    std::queue<int> queue;
    std::vector<Color> colors(edges.size(), Grey);
    for (int i = 0; i < edges.size(); i++) {
        if (colors[i] == Grey) {
            queue.push(i);
            colors[i] = Black;
            while (!queue.empty()) {
                int cur = queue.front();
                queue.pop();
                for (int j = 0; j < edges[cur].size(); j++) {
                    if (edges[cur][j] == 1) {
                        if (colors[j] == Grey) {
                            queue.push(j);
                            colors[j] = colors[cur] == Black ? White : Black;
                        } else {
                            if (colors[cur] == colors[j]) {
                                std::cout << " there is no such partition" << std::endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << " The Black ones:";
    for (int i = 0; i < edges.size(); i++)
        if (colors[i] == Black)
            std::cout << i << " ";
    std::cout << std::endl;
    std::cout << " The White ones:";
    for (int i = 0; i < edges.size(); i++)
        if (colors[i] == White)
            std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector< std::vector<int> > edges(5, std::vector<int>(5, 0));
    edges[0][1] = 1;
    edges[1][0] = 1;
    edges[1][2] = 1;
    edges[2][1] = 1;
    edges[3][4] = 1;
    edges[4][3] = 1;
    Partition(edges);
    edges[0][2] = 1;
    edges[2][0] = 1;
    Partition(edges);
    return 0;
}

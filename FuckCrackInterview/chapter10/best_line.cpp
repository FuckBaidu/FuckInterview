/**
 * 10.6 in <Crack the code interview>.
 * Given a two dimensional graph with poins on it, find a line which passes
 * the most number of points.
 */
#include <iostream>
#include <vector>
#if __GNUC__>2
#include <ext/hash_map>
using __gnu_cxx::hash_map;
#else
#include <hash_map>
#endif

struct Line {
    double slope;
    double intercept;

    Line(std::pair<int, int> start, std::pair<int, int> end) {
        if (start.first == end.first) {
            slope = INT_MAX;
            intercept = -1 * start.first;
        } else {
            slope = (end.second - start.second) / (end.first - start.first);
            intercept = start.second - slope * start.first;
        }
    }

    Line() : intercept(0.0), slope(0.0) { }

    bool operator==(const Line &other) const {
        return slope == other.slope && intercept == other.intercept;
    }
};

struct Hash {
    size_t operator()(const Line& line) const {
        return (int)line.slope * 97 | (int)line.intercept * 103;
    }
};

Line FindBestLine(std::vector< std::pair<int, int> > &graph) {
    int max = 0;
    Line best_line;
    hash_map<Line, int, Hash> hash_map;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = i + 1; j < graph.size(); j++) {
            Line line(graph[i], graph[j]);
            if (hash_map.find(line) == hash_map.end())
                hash_map[line] = 1;
            else
                hash_map[line]++;
            if (max < hash_map[line]) {
                max = 0;
                best_line = line;
            }
        }
    }
    return best_line;
}

void Test() {
    std::vector< std::pair<int, int> > graph;
    graph.push_back(std::make_pair(3, 4));
    graph.push_back(std::make_pair(3, 3));
    graph.push_back(std::make_pair(2, 3));
    graph.push_back(std::make_pair(1, 2));
    Line line = FindBestLine(graph);
    std::cout << "Points:";
    for (int i = 0; i < graph.size(); i++)
        std::cout << "(" << graph[i].first << "," << graph[i].second << ")";
    std::cout << std::endl;
    if (line.slope == INT_MAX)
        std::cout << "Best Line is x = " << -1 * line.intercept;
    else
        std::cout << "Best Line is y = " << line.slope <<" * x + " << line.intercept;
}

int main() {
    Test();
    return 0;
}

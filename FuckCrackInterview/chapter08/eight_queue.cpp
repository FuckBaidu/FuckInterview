/**
 * 8.8 in <Crack the code interview>.
 * Write an algorithm to print all ways of arranging eight queues on a chess board 
 * so that none of them share the same row, column or diagonal
 */
#include <iostream>
#include <vector>
#define N 8
void ArrangeQueues(std::vector< std::pair<int, int> > &result) {
    if (result.size() == N) {
        std::cout << "Solution:" << std::endl;
        for (int i = 0; i < result.size(); i++)
            std::cout << "<" << result[i].first << "," << result[i].second << ">    " <<std::endl;
    } else {
        std::pair<int, int> cur;
        cur.first = result.size();
        for (int i = 0; i < N; i++) {
            cur.second = i;
            bool is_conflict = false;
            for (int j = 0; j < result.size(); j++) {
                std::pair<int, int> prev = result[j];
                if (prev.second == cur.second 
                    || abs(prev.first - cur.first) == abs(prev.second - cur.second)) {
                    is_conflict = true;
                    break;
                }
            }
            if (!is_conflict) {
                result.push_back(cur);
                ArrangeQueues(result);
                result.erase(result.begin() + cur.first, result.end());
            }
        }
    }
}

void ArrangeQueues() {
    std::vector< std::pair<int, int> > result;
    ArrangeQueues(result);
}


int main() {
    ArrangeQueues();
    return 0;
}

/**
 * 10.7 in <Crack the code interview>
 * Design an algorithm to find out the kth number such that the only prime factors
 * are 3,5,7
 */
#include <iostream>
#include <queue>
int FindKthNumber(int k) {
    int cur = 1;
    std::queue<int> queue[3];
    queue[0].push(1);
    for (int i = 1; i <= k; i++) {
        int min = 0;
        if (!queue[1].empty() && queue[min].front() > queue[1].front())
            min = 1;
        if (!queue[2].empty() && queue[min].front() > queue[2].front())
            min = 2;
        cur = queue[min].front();
        queue[min].pop();
        switch (min) {
        case 0:
            queue[0].push(cur * 3);
        case 1:
            queue[1].push(cur * 5);
        case 2:
            queue[2].push(cur * 7);
            break;
        }
    }
    return cur;
}

int main() {
    int k = 20;
    std::cout << "Ugly number is: ";
    for (int i = 1; i <= k; i++)
        std::cout << FindKthNumber(i) << " ";
    std::cout << std::endl;
    return 0;
}

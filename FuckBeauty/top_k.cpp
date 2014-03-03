#include <vector>
#include <queue>
#include <iostream>
#include <assert.h>
std::vector<int> TopK(const std::vector<int> &input, int k) {
    assert(k > 0);
    std::vector<int> result;
    std::priority_queue<int> heap;
    for (int i = 0; i < input.size(); i++) {
        if (heap.size() < k) {
            heap.push(input[i]);
        } else {
            if (input[i] < heap.top()) {
                heap.pop();
                heap.push(input[i]);
            }
        }
    }
    while (!heap.empty()) {
        result.push_back(heap.top());
        heap.pop();
    }
    return result;
}

int Partition(std::vector<int> &input, int begin, int end) {
    int len = end - begin + 1;
    std::swap(input[rand() % len + begin], input[end]);
    int j = begin - 1;
    for (int i = begin; i < end; i++)
        if (input[i] < input[end])
            std::swap(input[++j], input[i]);
    std::swap(input[++j], input[end]);
    return j;
}

void TopK(std::vector<int> &input, int begin, int end, int k) {
    int pivot = Partition(input, begin, end);
    int len = pivot - begin + 1;
    if (len == k)
        return;
    else if (len > k)
        TopK(input, begin, pivot - 1, k);
    else
        TopK(input, pivot + 1, end, k - len);
}

std::vector<int> TopK2(std::vector<int> &input, int k) {
    TopK(input, 0, (int)input.size() - 1, k);
    return std::vector<int>(input.begin(), input.begin() + k);
}

void Test() {
    srand(time(NULL));
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> input(a, a + 10);
    std::random_shuffle(input.begin(), input.end());
    std::cout << "input:";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    std::vector<int> result = TopK(input, 5);
    std::cout << "Output:";
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    std::random_shuffle(input.begin(), input.end());
    std::cout << "input:";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    result = TopK2(input, 5);
    std::cout << "Output:";
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main() {
    Test();
    return 0;
}

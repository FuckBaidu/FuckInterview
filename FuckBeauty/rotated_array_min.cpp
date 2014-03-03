#include <vector>
#include <iostream>
int Min(const std::vector<int> &input) {
    int begin = 0, end = (int)input.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (mid > 0 && input[mid] < input[mid - 1])
            return input[mid];
        if (input[mid] <= input[end])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return input[begin];
}

int main() {
    std::vector<int> input;
    for (int i = 1; i <= 10; i++)
        input.push_back(i);
    std::cout << "input:";
    for (int i = 0; i < 10; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
    std::cout << "Min:" << Min(input) << std::endl;
    for (int i = 0; i < 10; i++) {
        std::vector<int> tmp(input);
        std::reverse(tmp.begin(), tmp.begin() + i);
        std::reverse(tmp.begin() + i, tmp.end());
        std::reverse(tmp.begin(), tmp.end());
        std::cout << "input:";
        for (int i = 0; i < 10; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;
        std::cout << "Min:" << Min(tmp) << std::endl;
    }
    return 0;
}

/**
 * Write a method to find the element which has occured for at least N/3 times, where N is the length of the array
 */
#include <vector>
#include <iostream>
int FindOutlier(std::vector<int> &array) {
    int counts[2] = {0, 0};
    int outliers[2] = {-1, -1};
    for (int i = 0; i < array.size(); i++) {
        bool is_equal = false;
        for (int j = 0; j < 2; j++) {
            if (array[i] == outliers[j] ) {
                counts[j]++;
                is_equal = true;
                break;
            }
        }
        if (is_equal)
            continue;
        bool is_new = false;
        for (int j = 0; j < 2; j++) {
            if (counts[j] == 0) {
                counts[j]++;
                outliers[j] = array[i];
                is_new = true;
                break;
            }
        }
        if (is_new)
            continue;
        for (int j = 0; j < 2; j++)
            if (--counts[j] == 0)
                outliers[j] = -1;
    }

    if (counts[0] >= counts[1])
        return outliers[0];
    else
        return outliers[1];
}

void RandomShuffle(std::vector<int> &output) {
    for (int i = output.size() - 1; i > 0; i--)
        std::swap(output[i], output[rand() % (i + 1)]);
}

void GenerateRandomArray(int num, std::vector<int> &output) {
    int num_outliers = 0, outlier = rand() % 10;
    while (num_outliers <= num / 3)
        num_outliers = rand() % (num + 1);
    for (int i = 0; i < num; i++) {
        if (i < num_outliers) {
            output.push_back(outlier);
        } else {
            int cur;
            while ((cur = rand() % 10) == outlier);
            output.push_back(cur);
        }
    }
    RandomShuffle(output);
    std::cout << "Input: ";
    for (int i = 0; i < output.size(); i++)
        std::cout << output[i] << " ";
    std::cout << std::endl;
}

void Test(int num) {
    std::vector<int> array;
    GenerateRandomArray(num, array);
    std::cout << "The outliers is " << FindOutlier(array) << std::endl << std::endl;
}

int main() {
    srand(time(NULL));
    Test(1);
    Test(6);
    Test(8);
    Test(15);
    return 0;
}

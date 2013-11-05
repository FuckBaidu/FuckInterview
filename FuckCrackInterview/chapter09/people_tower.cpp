/**
 * 9.7 in <Crack the code interview>.
 * A cicus is designing a tower routine consisting of people standing atop
 * on one anthoer's shoulders.For practice and aesthetic reasons, each person
 * must be both lighter and shorter than the person below him or her. Give the
 * heights and weights of each person in the circus, write a method to compute
 * the larest possible number of people in such a tower
 */
#include "util.h"
#include <iostream>
#include <vector>
struct Person {
    int height;
    int weight;

    Person(int _height, int _weight) : height(_height), weight(_weight) { }

    bool operator<(const Person &other) const {
        return (height < other.height);
    }
    bool operator>(const Person &other) const {
        return (height > other.height);
    }
    bool operator==(const Person &other) const {
        return (height == other.height);
    }
};

void CreatePeopleTower(Person *a, int len, std::vector<Person> &result) {
    int *parents = new int[len];
    QuickSort(a, len);
    std::vector<int> max_indices;
    for (int i = 0; i < len; i++) {
        int pos;
        if (max_indices.empty() || a[max_indices.back()].weight <= a[i].weight) {
            max_indices.push_back(i);
            pos = max_indices.size() - 1;
        } else {
            int begin = 0, end = max_indices.size() - 1;
            while (begin <= end) {
                int mid = (begin + end) / 2;
                if (a[max_indices[mid]].weight == a[i].weight)
                    break;
                else if (a[max_indices[mid]].weight < a[i].weight)
                    begin = mid + 1;
                else
                    end = mid - 1;
            }
            max_indices[begin] = i;
            pos = begin;
        }
        if (pos == 0)
            parents[i] = -1;
        else
            parents[i] = max_indices[pos - 1];
    }
    for (int i = max_indices.back(); i != -1; i = parents[i]) {
        result.push_back(a[i]);
    }
    delete []parents;
}

void Test(Person *a, int len) {
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < len; i++)
        std::cout << a[i].height << "," << a[i].weight << std::endl;
    std::vector<Person> result;
    CreatePeopleTower(a, len, result);
    std::cout << "Output:" << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i].height << "," << result[i].weight << std::endl;
}

int main() {
    Person a[] = {Person(65, 100), Person(70, 150), Person(56, 90), Person(75, 190),
                  Person(60, 95), Person(68, 110)};
    Test(a, 6);
    Person b[] = {Person(65, 100), Person(68, 95), Person(56, 90), Person(70, 110),
                  Person(60, 120), Person(63, 110), Person(75, 120)};
    Test(b, 7);
    return 0;
}

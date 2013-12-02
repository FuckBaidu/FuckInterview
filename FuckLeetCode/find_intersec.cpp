/**
 * Find the intersections of two sorted arrays
 * http://leetcode.com/2010/03/here-is-phone-screening-question-from.html
 */
#include <vector>
#include <iostream>

void FindIntersection(const std::vector<int> &a, const std::vector<int> &b,
        std::vector<int> &intersection) {
    int i = 0, j = 0;
    bool find_intersection = false;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            find_intersection = true;
            intersection.push_back(a[i]);
            i++;
            j++;
        } else {
            if (find_intersection)
                break;
            if (a[i] < b[j])
                i++;
            else
                j++;
        }
    }
}

int main() {
    std::vector<int> a, b, intersection;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(8);
    FindIntersection(a, b, intersection);
    std::cout << "a: ";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << "b: ";
    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    std::cout << "intersection: ";
    for (int i = 0; i < intersection.size(); i++)
        std::cout << intersection[i] << " ";
    std::cout << std::endl;
    return 0;
}

/**
 * 9.10 in <Crack the code interview> 5th edition.
 * You have a stack of n boxes, with the width w, heights h, and depth di.
 * The boxes cannot be rotated, and can only be stacked on top of one
 * another if each box in the stack is strictly larger than the box above it
 * in width, depth and height. Implement an algorithm to build the tallest stack
 * possibile, where the height is the sum of the heights of each box
 */
#include <iostream>
#include <vector>
#include <algorithm>

struct Box {
    int depth;
    int width;
    int height;

    Box (int _depth, int _width, int _height)
        : depth(_depth), width(_width), height(_height) { }

    bool operator<(const Box &other) const {
        return height < other.height;
    }

    bool operator==(const Box &other) const {
        return height == other.height;
    }
};

void GetMaxStackHeight(std::vector<Box> &boxes) {
    std::sort(boxes.begin(), boxes.end());
    int *max_heights = new int[boxes.size()];
    int *predecessor = new int[boxes.size()];
    for (int i = 0; i < boxes.size(); i++) {
        max_heights[i] = boxes[i].height;
        predecessor[i] = -1;
        for (int j = 0; j < i; j++) {
            if (boxes[j].depth <= boxes[i].depth && boxes[j].width <= boxes[i].width) {
                if (max_heights[j] + boxes[i].height > max_heights[i]) {
                    max_heights[i] = max_heights[j] + boxes[i].height;
                    predecessor[i] = j;
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < boxes.size(); i++) {
        if (max_heights[max] < max_heights[i])
            max = i;
    }

    std::cout << "The boxes are: ";
    for (int i = 0; i < boxes.size(); i++) {
        std::cout << "(" << boxes[i].depth << "," << boxes[i].width << ","
            << boxes[i].height<< ") ";
    }
    std::cout << std::endl;
    std::cout << "Maximum heights of the boxes stack is " << max_heights[max] << std::endl;
    std::cout << "The stack is(Bottom-up): ";
    for (int i = max; i != -1; i = predecessor[i]) {
        std::cout << "(" << boxes[i].depth << "," << boxes[i].width << ","
            << boxes[i].height<< ") ";
    }
    std::cout << std::endl;
    delete[] max_heights;
    delete[] predecessor;
}

int main() {
    std::vector<Box> boxes;
    boxes.push_back(Box(3, 3, 3));
    boxes.push_back(Box(2, 4, 5));
    boxes.push_back(Box(4, 6, 4));
    boxes.push_back(Box(3, 4, 4));
    boxes.push_back(Box(5, 7, 2));
    boxes.push_back(Box(5, 5, 3));
    boxes.push_back(Box(3, 5, 3));
    GetMaxStackHeight(boxes);
    return 0;
}

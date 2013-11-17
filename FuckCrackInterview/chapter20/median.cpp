/**
 * 20.8 in <Crack the code interview>.
 * Numbers are randomly generated and passed to a method. Write a method to
 * find and maintain the median value as new values are generated
 */
#include <iostream>
#include <vector>
#include <assert.h>
void InsertHeap(std::vector<int> &heap, int n, bool is_max_heap) {
    heap.push_back(n);
    int cur = heap.size() - 1, parent = (cur - 1) / 2;
    while (parent >= 0) {
        if (is_max_heap) {
            if (heap[parent] < heap[cur])
                std::swap(heap[parent], heap[cur]);
            else
                break;
        } else {
            if (heap[parent] > heap[cur])
                std::swap(heap[parent], heap[cur]);
            else
                break;
        }
        cur = parent;
        parent = (cur - 1) / 2;
    }
}

void Heapify(std::vector<int> &heap, bool is_max_heap) {
    int cur = 0;
    while (cur < heap.size()) {
        int left = cur * 2 + 1;
        int right = cur * 2 + 2;
        int root = cur;
        if (left < heap.size()) {
            if (is_max_heap && heap[left] > heap[root])
                root = left;
            else if (!is_max_heap && heap[left] < heap[root])
                root = left;
        }
        if (right < heap.size()) {
            if (is_max_heap && heap[right] > heap[root])
                root = right;
            else if (!is_max_heap && heap[right] < heap[root])
                root = right;
        }
        if (root == cur) {
            break;
        } else {
            std::swap(heap[cur], heap[root]);
            cur = root;
        }
    }
}

int PopHeapRoot(std::vector<int> &heap, bool is_max_heap) {
    int result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    Heapify(heap, is_max_heap);
    return result;
}

int FindMedian(std::vector<int> &vec) {
    std::vector<int> min_heap(1, INT_MAX), max_heap(1, INT_MIN);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < max_heap[0]) {
            if (max_heap.size() > min_heap.size()) {
                int root = PopHeapRoot(max_heap, true);
                InsertHeap(min_heap, root, false);
            }
            InsertHeap(max_heap, vec[i], true);
        } else if (vec[i] > min_heap[0]) {
            if (min_heap.size() >= max_heap.size()) {
                int root = PopHeapRoot(min_heap, false);
                InsertHeap(max_heap, root, true);
            }
            InsertHeap(min_heap, vec[i], false);
        } else {
            if (min_heap.size() >= max_heap.size())
                InsertHeap(max_heap, vec[i], true);
            else
                InsertHeap(min_heap, vec[i], false);
        }
    }
    return max_heap[0];
}

void Test() {
    std::vector<int> vec;
    for (int i = 0; i < 50; i++)
        vec.push_back(rand() % 100);
    int median = FindMedian(vec);
    std::sort(vec.begin(), vec.end());
    std::cout << "Input: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Real Median is " << vec[24] << std::endl;
    std::cout << "Median I found is " << median << std::endl;
    assert(vec[24] == median);
}

int main() {
    srand(time(NULL));
    Test();
    return 0;
}

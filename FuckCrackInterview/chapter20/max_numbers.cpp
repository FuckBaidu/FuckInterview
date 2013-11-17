/**
 * 20.6 in <Crack the code interview>.
 * Describe an algorithm to find the largest 1 million numbers in 1 billion numbers
 * Assume that the computer memory can hold all one billion numbers
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
int Partition(std::vector<int> &vec, int begin, int end) {
    std::swap(vec[rand() % (end - begin + 1) + begin], vec[end]);
    int j = begin - 1;
    for (int i = begin; i < end; i++) {
        if (vec[i] >= vec[end]) {
            j++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[j + 1], vec[end]);
    return j + 1;
}

void LargestKNumber(std::vector<int> &vec, int k) {
    int pivot, begin = 0, end = vec.size() -1;
    while ((pivot = Partition(vec, begin, end)) != k) {
        if (pivot > k)
            end = pivot - 1;
        else
            begin = pivot + 1;
    }
}

void Heapify(std::vector<int> &heap, int i) {
    while (i < heap.size()) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min = i;
        if (left < heap.size() && heap[left] < heap[min])
            min = left;
        if (right < heap.size() && heap[right] < heap[min])
            min = right;
        if (min == i)
            break;
        std::swap(heap[i], heap[min]);
        i = min;
    }
}

void BuildHeap(std::vector<int> &heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        Heapify(heap, i);
}

void InsertHeap(std::vector<int> &heap, int n) {
    heap.push_back(n);
    int cur = heap.size() - 1;
    int parent = (cur - 1) / 2;
    while (parent >= 0) {
        if (heap[cur] < heap[parent]) {
            std::swap(heap[cur], heap[parent]);
            cur = parent;
            parent = (cur - 1)/2;
        } else {
            break;
        }
    }
}

void LargestKNumber(const std::vector<int> &vec, int k, std::vector<int> &heap) {
    heap.insert(heap.end(), vec.begin(), vec.begin() + k);
    BuildHeap(heap);
    for (int i = k; i < vec.size(); i++) {
        if (vec[i] > heap[0]) {
            heap[0] = heap.back();
            heap.pop_back();
            Heapify(heap, 0);
            InsertHeap(heap, vec[i]);
        }
    }
}

void Test() {
    std::vector<int> vec;
    for (int i = 0; i < 50; i++)
        vec.push_back(rand() % 20);
    std::cout << "Input: ";
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Use heap
    std::vector<int> heap;
    LargestKNumber(vec, 10, heap);

    // Sort result
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());

    // Use partition
    LargestKNumber(vec, 10);
    std::cout << "Sort: ";
    for (int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl;

    std::cout << "(Partition method)Larest 10 is ";
    for (int i = 0; i < 10; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "(Heap method)Larest 10 is ";
    for (int i = 0; i < 10; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
}

int main() {
    srand(time(NULL));
    Test();
    return 0;
}

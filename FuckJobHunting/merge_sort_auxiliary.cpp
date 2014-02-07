#include <vector>
#include <iostream>
void Print(std::vector<int> &A) {
    for (int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}


void Merge(std::vector<int> &A, std::vector<int> &B, int begin, int end) {
    int mid = (begin + end) / 2;
    int i = begin, j = mid + 1, k = begin;
    while (i <= mid || j <= end) {
        int a = i <= mid ? B[i] : INT_MAX;
        int b = j <= end ? B[j] : INT_MAX;
        if (a < b) {
            A[k++] = a;
            i++;
        } else {
            A[k++] = b;
            j++;
        }
    }
}

void MergeSort(std::vector<int> &A, std::vector<int> &B, int begin, int end, int level) {
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    MergeSort(A, B, begin, mid, level + 1);
    MergeSort(A, B, mid + 1, end, level + 1);
    // if (level & 1)
    //     std::swap(A, B);
    if (level & 1)
        Merge(B, A, begin, end);
    else
        Merge(A, B, begin, end);
}

void MergeSort(std::vector<int> &A) {
    if (A.empty())
        return;
    std::vector<int> B(A);
    MergeSort(A, B, 0, A.size() - 1, 0);
}

void Test(int *array, int n) {
    std::vector<int> A(array, array + n);
    for (int i = 0; i < 4; i++) {
        std::random_shuffle(A.begin(), A.end());
        Print(A);
        MergeSort(A);
        Print(A);
    }
}

int main() {
    srand(time(NULL));
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    Test(a, 7);
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test(b, 8);
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    Test(c, 15);
    int d[] = {1,2 ,3 ,4, 5};
    Test(d, 5);
    return 0;
}

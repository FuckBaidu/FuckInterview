#include <iostream>

static const int kCutOff = 4;
int InsertionSort(int A[], int begin, int end) {
    for (int i = begin + 1; i <= end; i++) {
        int cur = A[i], j = i - 1;
        while (j >= 0 && cur < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cur;
    }
}

// median of three partition
int Partition(int A[], int begin, int end) {
    int mid = (begin + end) / 2, j = begin - 1;
    if (A[begin] > A[end])
        std::swap(A[begin], A[end]);
    if (A[mid] > A[end])
        std::swap(A[mid], A[end]);
    if (A[begin] > A[mid])
        std::swap(A[begin], A[mid]);
    std::swap(A[mid], A[end - 1]);
    for (int i = begin; i < end - 1; i++)
        if (A[i] < A[end - 1])
            std::swap(A[++j], A[i]);
    std::swap(A[++j], A[end - 1]);
    return j;
}

void QuickSort(int A[], int begin, int end) {
    if (begin < end) {
        if (end - begin + 1 <= kCutOff) {
            InsertionSort(A, begin, end);
        } else {
            int pivot = Partition(A, begin, end);
            QuickSort(A, begin, pivot - 1);
            QuickSort(A, pivot + 1, end);
        }
    }
}

void QuickSort(int A[], int n) {
    QuickSort(A, 0, n - 1);
}

void Test(int A[], int n) {
    std::cout << "input:";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    QuickSort(A, n);
    std::cout << "output:";
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main () {
    srand(time(NULL));
    int *a = new int[100];
    for (int i = 0; i < 100; i++)
        a[i] = rand() % 25;
    Test(a, 20);
    return 0;
}

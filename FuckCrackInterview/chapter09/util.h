#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>

template <class T>
void PrintArray(T arr[], int len) {
    assert(len >= 0);
    for (int i = 0; i < len; i++)
        printf("%d ", (int)arr[i]);
    printf("\n");
}

template <class T>
void InsertionSort(T arr[], int len) {
    if (!arr || !len)
        return;
    for (int i = 1; i < len; i++) {
        T key = arr[i];
        int j = i - 1;
        for ( ; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

template <class T>
void SelectionSort(T arr[], int len) {
    if (!arr || !len)
        return;
    for (int i = 0; i < len; i++) {
        int min_index = i;
        for (int j = i; j < len; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        std::swap(arr[i], arr[min_index]);
    }
}

template <class T>
void BubbleSort(T arr[], int len) {
    if (!arr || !len)
        return;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

template <class T>
static inline void _Merge(T arr[], int begin, int mid, int end) {
    int *A = new T[mid - begin + 2];
    int *B = new T[end - mid + 1];
    memcpy(A, arr + begin, sizeof(T) * (mid - begin + 1));
    memcpy(B, arr + mid + 1, sizeof(T) * (end - mid));
    A[mid - begin + 1] = (T)INT_MAX;
    B[end - mid] = (T)INT_MAX;
    int i = 0, j = 0, k = begin;
    while (k <= end) {
        if (A[i] <= B[j])
            arr[k++] = A[i++];
        else
            arr[k++] = B[j++];
    }
    delete []A;
    delete []B;
}

template <class T>
static inline void _MergeSort(T arr[], int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        _MergeSort(arr, begin, mid);
        _MergeSort(arr, mid + 1, end);
        _Merge(arr, begin, mid, end);
    }
}

template <class T>
void MergeSort(T arr[], int len) {
    if (!arr || !len)
        return;
    _MergeSort(arr, 0, len - 1);
}

template <class T>
static inline int _Partition(T arr[], int begin, int end) {
    int pivot_index = rand() % (end - begin + 1) + begin;
    std::swap(arr[pivot_index], arr[end]);
    int i = begin, j = begin - 1;
    for( ; i < end; i++) {
        if (arr[i] < arr[end]) {
            j++;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[j + 1], arr[end]);
    return j + 1;
}

template <class T>
static inline void _QuickSort(T arr[], int begin, int end) {
    if (begin < end) {
        int pivot = _Partition(arr, begin, end);
        _QuickSort(arr, begin, pivot - 1);
        _QuickSort(arr, pivot + 1, end);
    }
}

template <class T>
void QuickSort(T arr[], int len) {
    if (!arr || !len)
        return;
    _QuickSort(arr, 0, len - 1);
}

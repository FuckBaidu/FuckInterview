/**
 * 1.1 in <Crack the code interview>.Implement an algorithm to determine if a string has all unique
 * characters, you can not use additional data structures
 */
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

void Swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char *Partition(char *start, char *end) {
    char *pivot = start + rand() % (end - start);
    Swap(pivot, end);
    pivot = end;

    int min_idx = -1;
    for (char *cur = start; cur != end; cur++) {
        if (*cur < *pivot) {
            min_idx++;
            Swap(start + min_idx, cur);
        }
    }
    Swap(start + min_idx + 1, pivot);
    pivot = start + min_idx + 1;
    return pivot;
}

void QuickSort(char *start, char *end) {
    if (start == end)
        return;
    char *pivot = Partition(start, end);
    if (pivot > start)
        QuickSort(start, pivot - 1);
    if (pivot < end)
        QuickSort(pivot + 1, end);
}

bool IsUniqueChars(char *str) {
    if (str == NULL)
        return true;
    QuickSort(str, str + strlen(str) - 1);
    printf("%s\n", str);
    for (const char *cur = str; *(cur + 1) != '\0'; cur++)
        if (*cur == *(cur + 1))
            return false;
    return true;
}
int main() {
    assert(IsUniqueChars(NULL) == true);
    char fuck1[] = "absdxcnmo0e";
    assert(IsUniqueChars(fuck1) == true);
    char fuck2[] = "287135624";
    assert(IsUniqueChars(fuck2) == false);
    return 0;
}

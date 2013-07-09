/*
 * Question 1.4 in <Crack the code interview>.Write method to determine if two strings are anagram
 * or not
 */
#include <assert.h>
#include <string.h>
bool IsAnagram(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL)
        return false;
    int len = strlen(str1);
    if (len != strlen(str2))
        return false;
    char counters[256];
    memset(counters, 0, sizeof(counters));
    for (int i = 0; i < len; i++)
        counters[str1[i]]++;
    for (int i = 0; i < len; i++)
        counters[str2[i]]--;
    for (int i = 0; i < sizeof(counters); i++)
        if (counters[i] != 0)
            return false;
    return true;
}


int main() {
    assert(!IsAnagram(NULL, "fuck"));
    assert(!IsAnagram("fucki", "fuck"));
    assert(!IsAnagram("fsdk", "fuck"));
    assert(IsAnagram("cufkfucksdsfa", "fucksdsfacfuk"));
    return 0;
}

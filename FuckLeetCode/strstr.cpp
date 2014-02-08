/*
 *Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
#include <string.h>
#include <assert.h>
#include <vector>
char* NaiveStrstr(char *haystack, char *needle) {
    if (!haystack || !needle)
        return NULL;
    int m = strlen(haystack), n = strlen(needle);
    for (int i = 0; i <= m - n; i++) {
        bool is_match = true;
        for (int j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                is_match = false;
                break;
            }
        }
        if (is_match)
            return haystack + i;
    }
    return NULL;
}

#define BASE 10007L
char* RabinStrstr(char *haystack, char *needle) {
    if (!haystack || !needle)
        return NULL;
    int n = strlen(haystack), m = strlen(needle);
    long hash_haystack = 0, hash_needle = 0, exp = 1;
    for (int i = 0; i < m; i++) {
        hash_haystack = hash_haystack * BASE + haystack[i];
        hash_needle = hash_needle * BASE + needle[i];
        exp *= BASE;
    }
    for (int i = 0; i <= n - m; i++) {
        if (hash_haystack == hash_needle)
            return haystack + i;
        hash_haystack = hash_haystack * BASE - haystack[i] * exp + haystack[i + m];
    }
    return NULL;
}

char* KMPStrstr(char *haystack, char *needle) {
    if (!haystack || !needle)
        return NULL;
    if (!*needle)
        return haystack;
    int n = strlen(haystack), m = strlen(needle), match_len = 0;
    std::vector<int> next(m, 0);
    for (int i = 1; i < m; i++) {
        while (needle[match_len] != needle[i] && match_len > 0)
            match_len = next[match_len - 1];
        if (needle[match_len] == needle[i])
            match_len++;
        next[i] = match_len;
    }
    match_len = 0;
    for (int i = 0; i < n; i++) {
        while (needle[match_len] != haystack[i] && match_len > 0)
            match_len = next[match_len - 1];
        if (needle[match_len] == haystack[i])
            match_len++;
        if (match_len == m)
            return haystack + i - m + 1;
    }
    return NULL;
}

char *StrStr(char *haystack, char *needle) {
    return KMPStrstr(haystack, needle);
}

int main() {
    assert(StrStr("fuck", "a") == NULL);
    assert(StrStr("fuck", "") != NULL);
    assert(StrStr("fuck", "fuck") != NULL);
    return 0;
}

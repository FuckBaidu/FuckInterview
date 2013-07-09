/*
 * Question 1.3 in < Crack the code interview>.Design an algorithm and write code to remove
 * duplicate characters in a string without using any additional buffer
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define TEST_BIT(bitmap, nr) ((bitmap) & (1 << (nr)))
#define SET_BIT(bitmap, nr) ((bitmap) |= (1 << (nr)))

void RemoveDuplicateChars(char *str) {
    if (str == NULL || !*str)
        return;
    int bitmap = 0;
    const char *cur = str;
    while (*str) {
        while (*cur && TEST_BIT(bitmap, *cur))
            cur++;
        if (*cur)
            SET_BIT(bitmap, *cur);

        *str = *cur;
        str++;
        cur++;
    }
}

int main() {
   RemoveDuplicateChars(NULL); 
   RemoveDuplicateChars(""); 
   char test1[] = "a";
   RemoveDuplicateChars(test1);
   assert(strcmp(test1, "a") == 0);
   char test2[] = "abcde";
   RemoveDuplicateChars(test2);
   assert(strcmp(test2, "abcde") == 0);
   char test3[] = "abcddefdeee";
   RemoveDuplicateChars(test3);
   assert(strcmp(test3, "abcdef") == 0);
   char test4[] = "abcddefdeeeg";
   RemoveDuplicateChars(test4);
   assert(strcmp(test4, "abcdefg") == 0);
}

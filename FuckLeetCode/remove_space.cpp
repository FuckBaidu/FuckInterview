/* remove spaces from a string. eg: abc de g->abcedg
 */

#include <iostream>
using namespace std;
void RemoveSpaces(char *str) {
    if (str == NULL)
        return;
    char *ptr1 = str;
    char *ptr2 = str;
    do {
        if (*ptr2 == ' ')
            ptr2++;
        *ptr1++ = *ptr2++;
    } while (*ptr1 != '\0') ;
}


int main() {
    char str[32] = "Hello world !";
    RemoveSpaces(str);
    cout << str << endl;
    RemoveSpaces(NULL);
    str[0] = ' ';
    str[1] = '0';
    str[2] = '\0';
    RemoveSpaces(str);
    cout << str << endl;
    return 0;
}

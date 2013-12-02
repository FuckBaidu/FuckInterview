/* remove spaces from a string. eg: abc de g->abcedg
 */

#include <iostream>
using namespace std;

void RemoveSpaces(char *str) {
    if (!str)
        return;
    char *i = str, *j = str;
    while (*i != '\0') {
        if (*i != ' ')
            *j++ = *i;
        i++;
    }
    *j = '\0';
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

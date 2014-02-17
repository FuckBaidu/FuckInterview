/*
 * 设定如下的对应关系( A=0,B=1,C=2,...,Z=25,AA=26,AB=27,...,AAA=xxx,...
 * )，编写一个转换函数，根据上面的规则把一个字符串转换为数字
 */
#include <assert.h>
int StrToNum(const char *str) {
    assert(str && *str);
    int result = -1;
    while (*str) {
        result = (result + 1) * 26 + *str - 'A';
        str++;
    }
    return result;
}

int main() {
    assert(StrToNum("A") == 0);
    assert(StrToNum("Z") == 25);
    assert(StrToNum("AB") == 27);
    assert(StrToNum("AA") == 26);
    return 0;
}

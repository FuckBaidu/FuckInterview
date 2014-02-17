/*
 * Given the sequence S1 = {a,b,c,d,...x,y,z,aa,ab,ac... } and given that this sequence corresponds
 * (term for term) to the sequence S2 = {0,1,2,3,...} Write code to convert an element of S2 to the
 * corresponding element of S1.
 */
#include <string>
#include <assert.h>

std::string NumToStr(int n) {
    std::string result;
    while (n != -1) {
        result.push_back(n % 26 + 'a');
        n = n / 26 - 1;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    assert(NumToStr(25) == "z");
    assert(NumToStr(27) == "ab");
    return 0;
}

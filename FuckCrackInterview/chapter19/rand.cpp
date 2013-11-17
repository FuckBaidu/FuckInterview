/**
 * 19.10 in <Crack the code interview>.
 * Write a method to generate a random number between 1 and 7, give a method
 * that generate a random number between 1 and 5.(i.e. Implement rand7() use rand5())
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int rand5() {
    return rand() % 5;
}

int rand7() {
    int num;
    while((num = rand5() * 5 + rand5()) >= 21);
    return num % 7;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d, %d\n", rand5(), rand7());
    }

}

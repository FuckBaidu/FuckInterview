/*Given a number represented as an array of digits, plus one to the number.*/
#include <vector>
#include <iostream>

std::vector<int> PlusOne(std::vector<int> &digits) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        digits[i] += carry;
        if (digits[i] <= 9) {
            carry = 0;
            break;
        } else  {
            carry = 1;
            digits[i] = 0;
        }
    }
    if (carry)
        digits.insert(digits.begin(), carry);
    return digits;
}

void Test(int A[], int n) {
    std::vector<int> input(A, A + n);
    std::cout << "Input: ";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i];
    std::cout << std::endl;
    std::vector<int> output = PlusOne(input);
    std::cout << "output: ";
    for (int i = 0; i < output.size(); i++)
        std::cout << output[i];
    std::cout << std::endl;
}

int main() {
    int a[] = {1, 2, 3};
    Test(a, 3);
    int b[] = {1, 2, 9};
    Test(b, 3);
    int c[] = {9, 9, 9};
    Test(c, 3);
    return 0;
}

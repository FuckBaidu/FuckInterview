/*
 * Compute and return the square root of x.
 */
#include <iostream>
#include <cmath>
const static double kEpsilon = 0.001;
const static int kMultiply = (int)(1 / kEpsilon);

double Adjust(double input) {
    return (double)(int)(input * kMultiply) / kMultiply;
}

double SquareRoot(double x) {
    assert(x >= 0);
    double begin, end;
    if (x < 1) {
        begin = x;
        end = 1;
    } else {
        begin = 1;
        end = x;
    }
    while (end - begin >= kEpsilon) {
        double mid = (begin + end) / 2;
        double result = mid * mid;
        if (std::abs(x - result) < kEpsilon)
            return Adjust(mid);
        else if (result > x)
            end = mid - kEpsilon;
        else
            begin = mid + kEpsilon;
    }
    return Adjust(end);
}

void Test(double x) {
    std::cout << "sqrt(" << x << ") = " << SquareRoot(x) << std::endl;
}
int main() {
    Test(0);
    Test(2);
    Test(4);
    Test(8);
    Test(0.25);
    Test(0.5);
    Test(20);
    return 0;
}

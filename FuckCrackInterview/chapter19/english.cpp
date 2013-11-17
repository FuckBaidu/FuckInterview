/**
 * 19.6 in <Crack the code interview>.
 * Given an integer between 0 and 999,999, print an English phrase that describe
 * the integer(eg."One Thousand, Two Hundred and Thirty Four")
 */
#include <string>
#include <iostream>

std::string PrintInt(int n) {
    if (n == 0) {
        return "Zero";
    } else if (n >= 1000) {
        return PrintInt(n / 1000) + " Thousand, " + PrintInt(n % 1000);
    } else {
        static std::string word_units[] = {"", "One", "Two", "Three", "Four", "Five",
                                    "Six", "Seven", "Eight", "Nine", "Ten",
                                    "Eleven", "Twelve", "Thirteen, ""Fourteen",
                                    "Fifteen", "Sixteen", "Seventeen", "Eighteen"
                                    "Nineteen"};
        static std::string word_tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                                          "Sixty", "Seventy", "Eighty", "Ninety"};
        int cur = n / 100;
        std::string hundreds_str, tens_str, units_str;
        if (cur != 0) {
            hundreds_str = word_units[cur] + " Hundred ";
            n -= cur * 100;
        }
        if (n >= 20) {
            cur = n / 10;
            tens_str = " and " + word_tens[cur];
            n -= cur * 10;
        }
        if (n != 0) {
            if (n > 10)
                units_str = " and ";
            units_str += word_units[n];
        }
        return hundreds_str + tens_str + units_str;
    }
}

void Test(int n) {
    std::cout << "Number is "<< n << std::endl;
    std::cout << "English phrase is "<< PrintInt(n) << std::endl;
}

int main () {
    Test(1020);
    Test(3512);
    Test(100);
    return 0;
}

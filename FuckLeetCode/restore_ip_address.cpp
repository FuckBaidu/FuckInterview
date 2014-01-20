/*
 * Given a string containing only digits, restore it by returning all possible valid IP address
 * combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <vector>
#include <iostream>

void RestoreIpAddresses(const std::string &s, int idx, std::vector<std::string> path, std::vector<std::string> &result) {
    if (idx == s.length()) {
        if (path.size() == 4) {
            std::string ip_address = path[0];
            for (int i = 1; i < 4; i++)
                ip_address += "." + path[i];
            result.push_back(ip_address);
        }
    } else {
        int max_len = s[idx] == '0' ? 1 : std::min(3, (int)s.length() - idx);
        for (int len = 1; len <= max_len; len++) {
           // 2 enough room for other component of string
           if (s.length() - idx - len < 3 - path.size())
               break;
           // 3 no spare letters
           if (s.length() - idx - len > 3 * (3 - path.size()))
               continue;
           // 4 valid component
           std::string component = s.substr(idx, len);
           int cur = atoi(component.c_str());
           if (cur > 255)
               break;
           path.push_back(component);
           RestoreIpAddresses(s, idx + len, path, result);
           path.pop_back();
        }
    }
}

std::vector<std::string> RestoreIpAddresses(const std::string &s) {
    std::vector<std::string> path, result;
    if (!s.empty())
        RestoreIpAddresses(s, 0, path, result);
    return result;
}

void Test(const std::string &s) {
    std::vector<std::string> result = RestoreIpAddresses(s);
    std::cout << "string:" << s << std::endl;
    std::cout << "result" << std::endl;
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;
}

int main() {
    Test("25525511135");
    Test("010010");
    return 0;
}

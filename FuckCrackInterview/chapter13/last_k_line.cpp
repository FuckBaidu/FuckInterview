/**
 * 13.1 in <Crack the code interview>.
 * Write a method to print the last K lines of an input file
 */
#include <iostream>
#include <fstream>
#include <string>

#define K 10

int main(int argc, const char *argv[]) {
    if (argc < 2)
        return -1;
    const char *path = argv[1];
    std::ifstream ifs;
    ifs.open(path);
    if (ifs.is_open()) {
        std::string buffer[K], tmp;
        int line_count = 0;
        while (std::getline(ifs, tmp)) {
            if (!ifs.eof())
                buffer[line_count++ % K] = tmp;
        }
        //while (!ifs.eof()) {
        //        ifs >> buffer[line_count++ % K];
        //}
        int offset = line_count % K;
        for (int i = offset; i < K + offset; i++)
            if (i % K < line_count)
                std::cout << buffer[i % K] << std::endl;
    }
    return 0;
}

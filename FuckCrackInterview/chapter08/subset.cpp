/**
 * 8.3 in <Crack the code interview>.
 * Write a method to return all the subsets of a set
 */
#include <iostream>
#include <vector>
#include <set>

std::vector< std::set<int> > ComputeSubSets(const std::set<int> &set) {
    std::vector< std::set<int> > result;
    int result_size = 1 << set.size();
    for (int i = 0; i < result_size; i++) {
        std::set<int> tmp_set;
        int j = i, bit_index = 0;
        while (j != 0) {
            if (j & 1) {
                std::set<int>::const_iterator iter = set.begin();
                for (int k = 0; k < bit_index; k++)
                    iter++;
                tmp_set.insert(*iter);
            }
            j >>= 1;
            bit_index++;
        }
        result.push_back(tmp_set);
    }
    return result;
}

void Test(const std::set<int> &set) {
    std::vector< std::set<int> > sets = ComputeSubSets(set);
    for (int i = 0; i < sets.size(); i++) {
        std::set<int>::const_iterator iter = sets[i].begin();
        for (; iter!= sets[i].end(); iter++)
            std::cout << *iter;
        std::cout << std::endl;
    }
}

int main() {
    std::set<int> set;
    for (int i = 0; i < 4; i++)
        set.insert(i);
    Test(set);
    return 0;
}

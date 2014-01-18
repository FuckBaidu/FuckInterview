/*
 * Problem 1:
 * Given numRows, generate the first numRows of Pascal's triangle.

   For example, given numRows = 5,
   Return
   
   [
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
   ]

 Problem 2:
 Given an index k, return the kth row of the Pascal's triangle.
  For example, given k = 3,
  Return [1,3,3,1].
  Note:
  Could you optimize your algorithm to use only O(k) extra space?
 */
#include <vector>
std::vector<std::vector<int> > Generate(int numRows) {
    std::vector< std::vector<int> > result;
    if (numRows > 0) {
        result.push_back(std::vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            std::vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < (int)result[i - 1].size() - 1; j++)
                tmp.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            tmp.push_back(1);
            result.push_back(tmp);
        }
    }
    return result;
}

std::vector<int> GetRow(int rowIndex) {
    assert(rowIndex >= 0);
    std::vector<int> result(rowIndex + 1);
    for (int i = 0; i <= rowIndex; i++) {
        result[0] = result[i] = 1;
        for (int j = i - 1; j >= 1; j--)
            result[j] = result[j] + result[j - 1];
    }
    return result;
}

int main() {
    return 0;
}

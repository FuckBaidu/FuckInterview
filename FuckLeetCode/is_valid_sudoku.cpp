/*
 * Determine if a Sudoku is valid
 */
#include <vector>
#include <set>
#include <string>
#include <assert.h>
bool IsValidSudoku(std::vector< std::vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
        std::set<char> row, col, square;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                if (row.count(board[i][j]))
                    return false;
                row.insert(board[i][j]);
            }
            if (board[j][i] != '.') {
                if (col.count(board[j][i]))
                    return false;
                col.insert(board[j][i]);
            }
            int upper_left_row = i / 3 * 3, upper_left_col = i % 3 * 3;
            if (board[upper_left_row + j / 3][upper_left_col + j % 3] != '.') {
                if (square.count(board[upper_left_row + j / 3][upper_left_col + j % 3]))
                    return false;
                square.insert(board[upper_left_row + j / 3][upper_left_col + j % 3]);
            }
        }
    }
    return true;
}

int main() {
    std::vector< std::vector<char> > board;
    std::string a[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    for (int i = 0; i < 9; i++) {
        std::vector<char> tmp(a[i].begin(), a[i].end());
        board.push_back(tmp);
    }
    assert(IsValidSudoku(board));
    return 0;
}

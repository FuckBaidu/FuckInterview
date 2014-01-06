#include <vector>
#include <iostream>

std::pair<int, int> NextCell(const std::vector< std::vector<char> > &board, std::vector< std::vector<int> > &scores) {
    int max_score = INT_MIN;
    std::pair<int, int> result(-1, -1);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                int cur_score = scores[0][i] + scores[1][j] + scores[2][i / 3 * 3 + j / 3];
                if (max_score < cur_score) {
                    result.first = i;
                    result.second = j;
                    max_score = cur_score;
                }
            }
        }
    }
    return result;
}

void UpdateScores(std::vector< std::vector<int> > &scores, std::pair<int, int> pos, bool is_increment) {
    int add = is_increment ? 1 : - 1;
    scores[0][pos.first] += add;
    scores[1][pos.second] += add;
    scores[2][pos.first / 3 * 3 + pos.second / 3] += add;
}

#define TEST_BIT(bitmap, pos) ((bitmap) & (1 << ((pos) - 1)))
#define RESET_BIT(bitmap, pos) ((bitmap) &= ~(1 << ((pos) - 1)))

int GetValidValues(const std::vector< std::vector<char> > &board, std::pair<int, int> pos) {
    int bitmap = (1 << 9) - 1;
    std::pair<int, int> upper_left(pos.first / 3 * 3, pos.second / 3 * 3);
    for (int i = 0; i < 9; i++) {
        // check row
        if (board[pos.first][i] != '.')
            RESET_BIT(bitmap, board[pos.first][i] - '0');
        // check column
        if (board[i][pos.second] != '.')
            RESET_BIT(bitmap, board[i][pos.second] - '0');
        // check square
        std::pair<int, int> cur_pos(upper_left.first + i / 3, upper_left.second + i % 3);
        if (board[cur_pos.first][cur_pos.second] != '.')
            RESET_BIT(bitmap, board[cur_pos.first][cur_pos.second] - '0');
    }
    return bitmap;
}

bool Solve(std::vector< std::vector<char> > &board, std::vector< std::vector<int> > &scores) {
    std::pair<int, int> pos = NextCell(board, scores);
    if (pos.first == -1 && pos.second == -1)
        return true;
    int bitmap = GetValidValues(board, pos);
    if (bitmap == 0)
        return false;
    UpdateScores(scores, pos, true);
    for (int i = 1; i <= 9; i++) {
        if (TEST_BIT(bitmap, i)) {
            board[pos.first][pos.second] = i + '0';
            if (Solve(board, scores))
                return true;
        }
    }
    board[pos.first][pos.second] = '.';
    UpdateScores(scores, pos, false);
    return false;
}

void SolveSudoku(std::vector< std::vector<char> > &board) {
    std::vector< std::vector<int> > scores(3, std::vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.')
                UpdateScores(scores, std::make_pair(i, j), true);
        }
    }
    Solve(board, scores);
}

void Print(std::vector< std::vector<char> > &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::vector< std::vector<char> > board;
    std::string a[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    for (int i = 0; i < 9; i++) {
        std::vector<char> tmp(a[i].begin(), a[i].end());
        board.push_back(tmp);
    }
    Print(board);
    SolveSudoku(board);
    Print(board);
    return 0;
}

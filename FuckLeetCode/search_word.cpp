/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
 * are those horizontally or vertically neighboring. The same letter cell may not be used more than
 * once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */
#include <vector>
#include <string>
#include <stack>
#include <assert.h>
bool Solve(const std::vector< std::vector<char> > &board, const std::string &word, int index, std::pair<int, int> cur,
           std::vector< std::vector<bool> > &visited) {
    if (index == word.length() - 1)
        return true;
    visited[cur.first][cur.second] = true;
    std::pair<int, int> next;
    for (int i = 0; i < 4; i++) {
        switch(i) {
        case 0:    // up
            next.first = cur.first - 1;
            next.second = cur.second;
            break;
        case 1:  //down
            next.first = cur.first + 1;
            next.second = cur.second;
            break;
        case 2:    // left
            next.first = cur.first;
            next.second = cur.second - 1;
            break;
        case 3:  //right
            next.first = cur.first;
            next.second = cur.second + 1;
            break;        
        }
        if (next.first < 0 || next.first >= board.size() || next.second < 0 || next.second >= board[0].size())
            continue;
        // check if visited
        if (visited[next.first][next.second])
            continue;
        if (board[next.first][next.second] != word[index + 1])
            continue;
        if (Solve(board, word, index + 1, next, visited))
            return true;
    }
    visited[cur.first][cur.second] = false;
    return false;
}

bool Exist(std::vector< std::vector<char> > &board, std::string word) {
    if (word.empty())
        return true;
    if (board.empty() || board[0].empty())
        return false;
    int m = board.size(), n = board[0].size();
    std::vector< std::pair<int, int> > start_points;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == word[0])
                start_points.push_back(std::make_pair(i, j));
    std::vector< std::vector<bool> > visited (m, std::vector<bool>(n, false));
    for (int i = 0; i < start_points.size(); i++)
        if (Solve(board, word, 0, start_points[i], visited))
            return true;
    return false;
}

struct State {
    int row;
    int col;
    int len;
    State(int r, int c, int l) : row(r), col(c), len(l) { }
};

bool ExistIterative(std::vector< std::vector<char> > &board, std::string word) {
    if (word.empty())
        return true;
    if (board.empty() || board[0].empty())
        return false;
    int m = board.size(), n = board[0].size(), prev_len = 0;
    std::stack<State> stack;
    std::vector< std::vector<bool> > visited (m, std::vector<bool>(n, false));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == word[0])
                stack.push(State(i, j, 1));
    while (!stack.empty()) {
        State cur = stack.top();
        if (cur.len == word.length())
            return true;
        visited[cur.row][cur.col] = true;
        bool found_next = false;
        State next(cur.row, cur.col, cur.len + 1);
        if (prev_len <= cur.len) {
            for (int i = 0; i < 4; i++) {
                switch (i) {
                case 0: //up
                    next.row = cur.row - 1;
                    next.col = cur.col;
                    break;
                case 1:  // down
                    next.row = cur.row + 1;
                    next.col = cur.col;
                    break;
                case 2:  // left
                    next.row = cur.row;
                    next.col = cur.col - 1; 
                    break;
                case 3:  // right
                    next.row = cur.row;
                    next.col = cur.col + 1; 
                    break;
                }
                if (next.row >= 0 && next.row < m && next.col >= 0 && next.col < n 
                    && board[next.row][next.col] == word[next.len - 1] 
                    && !visited[next.row][next.col]) {
                    stack.push(next);
                    found_next = true;
                }
            }
        }
        if (!found_next) {
            visited[cur.row][cur.col] = false;
            stack.pop();
        }
        prev_len = cur.len;
    }
    return false;
}

int main() {
    std::vector< std::vector<char> > board;
    char a[][5] = { {"ABCE"}, {"SFCS"}, {"ADEE"} };
    for (int i = 0; i < 3; i++)
        board.push_back(std::vector<char>(a[i], a[i] + 4));
    assert(ExistIterative(board, "ABCCED"));
    assert(ExistIterative(board, "SEE"));
    assert(!ExistIterative(board, "ABCB"));
    return 0;
}

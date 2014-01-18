/*
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region .
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */
#include <vector>
#include <queue>
#include <iostream>

void Solve(std::vector< std::vector<char> > &board) {
    if (board.empty() || board[0].empty())
        return;
    int m = board.size(), n = board[0].size();
    std::queue< std::pair<int, int> > queue;
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O')
            queue.push(std::make_pair(i, 0));
        if (board[i][n - 1] == 'O')
            queue.push(std::make_pair(i, n - 1));
    }
    for (int i = 0; i < n; i++) {
        if (board[0][i] == 'O')
            queue.push(std::make_pair(0, i));
        if (board[m - 1][i] == 'O')
            queue.push(std::make_pair(m - 1, i));
    }
    while (!queue.empty()) {
        std::pair<int, int> cur = queue.front();
        queue.pop();
        if (board[cur.first][cur.second] != 'O')
            continue;
        board[cur.first][cur.second] = '$';
        // up
        if (cur.first > 0 && board[cur.first - 1][cur.second] == 'O')
            queue.push(std::make_pair(cur.first - 1, cur.second));
        // down
        if (cur.first < m - 1 && board[cur.first + 1][cur.second] == 'O')
            queue.push(std::make_pair(cur.first + 1, cur.second));
        // left
        if (cur.second > 0 && board[cur.first][cur.second - 1] == 'O')
            queue.push(std::make_pair(cur.first, cur.second - 1));
        // right
        if (cur.second < n - 1 && board[cur.first][cur.second + 1] == 'O')
            queue.push(std::make_pair(cur.first, cur.second + 1));
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '$')
                board[i][j] = 'O';
        }
    }
}

void PrintBoard(std::vector< std::vector<char> > &board) {
    std::cout << std::endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}

int main() {
    char tmp[][5] = {"XXXX", "XOOX", "XXOX", "XOXX"};
    std::vector< std::vector<char> > board;
    for (int i = 0; i < 4; i++) {
        std::vector<char> vec(tmp[i], tmp[i] + 4);
        board.push_back(vec);
    }
    PrintBoard(board);
    Solve(board);
    PrintBoard(board);
    return 0;
}

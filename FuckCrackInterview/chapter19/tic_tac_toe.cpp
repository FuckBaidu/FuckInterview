/**
 * 19.2 in <Crack the code interview>.
 * Design an algorithm to figure out if someone has won in a game of tic-tac-toe
 */
enum Color {
    RED,
    BLUE
};

bool HasWon(Color **a, int n) {
    bool same_diagonal = true, same_reverse_diagonal = true;
    for (int i = 0; i < n; i++) {
        bool same_column = true, same_row = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[i][0])
                same_row = false;
            if (a[j][i] != a[0][i])
                same_column = false;
        }
        if (same_column || same_row)
            return true;
        if (a[i][i] != a[0][0])
            same_diagonal = false;
        if (a[n - i - 1][i] != a[0][0])
            same_reverse_diagonal = false;
    }
    if (same_diagonal || same_reverse_diagonal)
        return true;

    return false;
}

int main() {
    return 0;
}

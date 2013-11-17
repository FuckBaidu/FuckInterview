/**
 * 19.5 in <Crack the code interview>.
 * Game of Master Mind
 */
#include <string>
std::pair<int, int> MasterMindGame(std::string real, std::string guess) {
    std::pair<int, int> result(0, 0);
    int counts_real[26], counts_guess[26];
    memset(counts_real, 0, sizeof(counts_real));
    memset(counts_guess, 0, sizeof(counts_guess));
    for (int i = 0; i < real.length(); i++) {
        if (real[i] == guess[i]) {
            result.first++;
        } else {
            counts_real[real[i] - 'A']++;
            counts_guess[guess[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        int min = std::min(counts_real[i], counts_guess[i]);
        if (min)
            result.second++;
    }
    return result;
}

int main() {
    assert(MasterMindGame("RGGB", "YRGB") == std::make_pair(2, 1));
    return 0;
}

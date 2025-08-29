#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string S) {
    unordered_map<char, int> seen; // stores last index of each char
    int left = 0, max_len = 0;

    for (int right = 0; right < S.size(); right++) {
        char c = S[right];

        if (seen.count(c) && seen[c] >= left) {
            left = seen[c] + 1; // move left past the duplicate
        }

        seen[c] = right; // update last seen index
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    string S;
    cin >> S; // input string
    cout << longestUniqueSubstring(S) << endl;
    return 0;
}

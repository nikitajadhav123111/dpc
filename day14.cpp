#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Count substrings with at most K distinct characters
    int atMostKDistinct(const string &s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            while ((int)freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            count += (right - left + 1);  // all substrings ending at right
        }

        return count;
    }

    int substrCountWithKDistinct(const string &s, int k) {
        if (k == 0) return 0;
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }
};

int main() {
    Solution sol;

    cout << sol.substrCountWithKDistinct("pqpqs", 2) << endl;        // 7
    cout << sol.substrCountWithKDistinct("aabacbebebe", 3) << endl; // 10
    cout << sol.substrCountWithKDistinct("a", 1) << endl;           // 1
    cout << sol.substrCountWithKDistinct("abc", 3) << endl;         // 1
    cout << sol.substrCountWithKDistinct("abc", 2) << endl;         // 2
    return 0;
}

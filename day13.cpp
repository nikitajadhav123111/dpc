#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;

        int start = 0, maxLen = 1;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expandAroundCenter(i, i);
            // Even length palindrome
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; // "bab"
    cout << sol.longestPalindrome("cbbd") << endl;  // "bb"
    cout << sol.longestPalindrome("a") << endl;     // "a"
    cout << sol.longestPalindrome("aaaa") << endl;  // "aaaa"
    cout << sol.longestPalindrome("abc") << endl;   // "a"
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringPermutations(string s) {
        vector<string> result;
        sort(s.begin(), s.end()); // sort to handle duplicates
        vector<bool> used(s.size(), false);
        string path;
        backtrack(s, used, path, result);
        return result;
    }

private:
    void backtrack(const string &s, vector<bool> &used, string &path, vector<string> &result) {
        if (path.size() == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (used[i]) continue;
            // Skip duplicates at the same depth
            if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

            used[i] = true;
            path.push_back(s[i]);
            backtrack(s, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution sol;
    string s = "abc";
    vector<string> permutations = sol.stringPermutations(s);

    for (auto &perm : permutations) {
        cout << perm << "\n";
    }
    return 0;
}

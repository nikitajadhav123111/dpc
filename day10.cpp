#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());  // sort the word to form the key
        anagramMap[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> grouped = groupAnagrams(strs);

    // Print the result
    for (auto& group : grouped) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}

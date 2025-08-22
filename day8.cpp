#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string text = "Hello world from GPT";
    stringstream ss(text);
    string word;
    vector<string> words;

    // Split into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Print in reverse order
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    cout << endl;

    return 0;
}

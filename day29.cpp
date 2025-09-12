#include <bits/stdc++.h>
using namespace std;

// Function to add two large numbers represented as strings
string addStrings(const string &a, const string &b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

// Function to compute nth Fibonacci number using DP
string fibonacci(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    vector<string> dp(n + 1);
    dp[0] = "0";
    dp[1] = "1";

    for (int i = 2; i <= n; i++) {
        dp[i] = addStrings(dp[i - 1], dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}

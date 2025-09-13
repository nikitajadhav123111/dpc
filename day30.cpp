#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    // dp[i] will store the minimum coins required for amount i
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);
    cout << result << endl; // Expected Output: 3

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove smaller elements (they are useless)
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);

        // Remove indices outside the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Start recording results after first k elements
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

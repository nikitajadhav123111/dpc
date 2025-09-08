#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Count frequencies of all elements
    for (int num : arr) {
        freq[num]++;
    }

    // Traverse again to maintain "first occurrence" order
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1; // If no element occurs exactly k times
}

int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;

    cout << "Output: " << firstElementKTimes(arr, k) << endl;  // Expected 1

    vector<int> arr2 = {2, 3, 4, 2, 2, 5, 5};
    k = 2;
    cout << "Output: " << firstElementKTimes(arr2,k);
    return 0;
}

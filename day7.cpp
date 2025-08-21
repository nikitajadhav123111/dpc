#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water = 0;
  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= left_max) {
        left_max = height[left];
          } else {
              water += left_max - height[left];
          }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water += right_max - height[right];
            }
            right--;
        }
      }    
    return water;
}

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water = " << trap(height1) << endl; // Output: 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Trapped water = " << trap(height2) << endl; // Output: 9

    return 0;
}

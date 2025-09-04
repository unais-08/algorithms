#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int majorityElementByHashing(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto& it : mpp) {
            if (it.second > (n / 2)) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }

   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                ele = nums[i];
            } else if (nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele) {
                ans++;
            }
        }
        if (ans > (n / 2)) {
            return ele;
        }
        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size() - 1;
        int low = 0;
        int high = n;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int getCeil(vector<int> &nums, int x) {
        int n = nums.size() - 1;
        int low = 0;
        int high = n;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        vector<int> ans;
        int ceil = lowerBound(nums, x);
        int floor = getCeil(nums, x);
        ans.push_back(nums[floor]);
        ans.push_back(nums[ceil]);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int firstOcc = -1;
        int lastOcc = -1;
        // find lower bound
        firstOcc = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // find upper bound
        lastOcc = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        // if the lower bound not pointing to target itself then just return
        // {-1,-1}
        if (firstOcc == n || nums[firstOcc] != target) {
            return {-1, -1};
        }

        // if we successfully found the lower bound then just substract 1 index
        // to get the element from upperBound
        return vector<int>{firstOcc, lastOcc - 1};
    }
};

int main() {
    return 0;
}
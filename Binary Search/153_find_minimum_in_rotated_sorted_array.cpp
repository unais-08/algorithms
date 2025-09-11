#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Early termination: if current range is sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            // Identify the sorted array(Either Left or Right)

            // right half is sorted
            if (nums[mid] <= nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
            // left half is sorted
            else {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
        }

        return ans;
    }
};
int main() {
    return 0;
}
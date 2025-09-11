#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool search(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == k) {
                return true;
            }

            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Identify the sorted array(Either Left or Right)

            // right half is sorted
            if (nums[mid] <= nums[high]) {
                if (k >= nums[mid] && k <= nums[high]) {
                    // element exists in the search space
                    low = mid + 1;
                } else {
                    // element does not exists in this search space
                    high = mid - 1;
                }
            }
            // left half is sorted
            else {
                if (k <= nums[mid] && k >= nums[low]) {
                    // element exists in the search space
                    high = mid - 1;
                } else {
                    // element does not exists in this search space
                    low = mid + 1;
                }
            }
        }

        return false;  // element not found
    }
};

int main() {
    return 0;
}
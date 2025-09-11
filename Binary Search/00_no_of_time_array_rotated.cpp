#include <bits/stdc++.h>
using namespace std;

int no_of_time_rotated(vector<int> nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (nums[low] <= nums[high]) return low;

        // Smallest element where the pivot happens
        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
            return mid;
        }
        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << no_of_time_rotated(nums) << endl;
    return 0;
}
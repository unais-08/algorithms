#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int upperBound(vector<int> &nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v = {3, 5, 8, 15, 19};
    int x = 3;
    Solution s;
    cout << "Index: " << s.upperBound(v, x) << endl;
    cout << "Index: " << (upper_bound(v.begin(), v.end(), 3)) - v.begin() << endl;
    return 0;
}
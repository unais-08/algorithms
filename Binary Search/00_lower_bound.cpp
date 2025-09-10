#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lowerBound(vector<int> &nums, int x) {
        // ans[x]>=ans[i]
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
};

int main() {
    vector<int> v = {3, 5, 8, 15, 19};
    int x = 3;
    Solution s;
    cout << "Index: " << s.lowerBound(v, x) << endl;
    cout << "Index: " << (lower_bound(v.begin(), v.end(), 3)) - v.begin() << endl;
    return 0;
}
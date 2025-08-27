#include <bits/stdc++.h>
using namespace std;

// TC O(n)
// SC O(1)
class Solution {
   public:
    void leftRotateByOnePlace(vector<int> &nums) {
        int n = nums.size();
        int temp = nums[0];
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = temp;
    }
};

int main() {
    vector<int> v = {10,1, 2, 3, 4, 5, 6};
    Solution s;
    s.leftRotateByOnePlace(v);
    for (auto &it : v) cout << it << " ";
    cout << endl;
}
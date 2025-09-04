#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> bruteForce(vector<int> &nums) {
        int maxi = nums[nums.size() - 1];
        vector<int> ans;
        ans.push_back(maxi);
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > maxi) {
                ans.push_back(nums[i]);
                maxi = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> v = {10, 22, 12, 3, 0, 6};
    Solution s;
    vector<int> leadersArray = s.bruteForce(v);
    for (auto &ele : leadersArray) {
        cout << ele << " ";
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n = nums.size();
        int query = n / 3;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for (auto& it : mpp) {
            if (it.second > floor(query)) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
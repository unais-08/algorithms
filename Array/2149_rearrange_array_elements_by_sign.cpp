#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size();
        int postIndex = 0;
        int negtIndex = 1;
        vector<int> ans(N, 0);
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) {
                ans[postIndex] = nums[i];
                postIndex += 2;
            } else {
                ans[negtIndex] = nums[i];
                negtIndex += 2;
            }
        }

        return ans;
    }
};
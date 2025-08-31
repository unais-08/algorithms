#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;  // stores maximum streak
        int count = 0;     // current streak of 1's

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;  // reset streak when encountering 0
            }
        }
        return maxCount;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& arr, int k) {
        int cnt = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mpp;

        mpp[0] = 1;

        for (int right = 0; right < arr.size(); right++) {
            prefix_sum += arr[right];

            if (mpp.find(prefix_sum - k) != mpp.end()) {
                cnt += mpp[prefix_sum - k];
            }
            mpp[prefix_sum]++;
        }

        return cnt;
    }
};
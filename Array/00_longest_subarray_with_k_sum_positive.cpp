#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int bruteForce(vector<int> &nums, int k, int n) {
        int lengthCnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    lengthCnt = max(lengthCnt, j - i + 1);
                }
            }
        }

        return lengthCnt;
    }

   public:
    int longestSubarray(vector<int> &nums, int k, int n) {
        int maxLen = 0;
        int right = 0;
        int left = 0;
        int sum = 0;
        while (right < nums.size()) {
            sum = sum + nums[right];

            while (sum > k && left <= right) {
                sum = sum - nums[left];
                left++;
            }

            if (sum == k) {
                maxLen = max(maxLen, (right - left) + 1);
            }

            right++;
        }
        return maxLen;
    }
};

int main() {
    vector<int> v = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = v.size();
    Solution s;
    cout << s.longestSubarray(v, k, n) << endl;
}
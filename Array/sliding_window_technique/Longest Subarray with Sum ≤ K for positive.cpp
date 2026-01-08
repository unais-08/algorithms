#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumAtMostK(const vector<int>& nums, int k) {
  int n = nums.size();
  int maxLen = 0;
  int sum = 0;
  int left = 0;

  for (int right = 0; right < n; right++) {
    sum += nums[right];
    while (sum > k) {
      sum = sum - nums[left];
      left++;
    }
    maxLen = max(maxLen, right - left + 1);
  }
  
  return maxLen;
}
int main() {
  vector<int> nums = {2, 1, 5, 1, 3, 2};
  int k = 7;
  int result = longestSubarrayWithSumAtMostK(nums, k);
  cout << "Length of longest subarray with sum at most " << k
       << " is: " << result << endl;
  return 0;
}
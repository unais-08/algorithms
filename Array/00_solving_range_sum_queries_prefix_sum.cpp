#include <bits/stdc++.h>
using namespace std;

vector<int> buildPrefixSum(const vector<int>& nums) {
  int n = nums.size();
  vector<int> prefixSum(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
  }
  return prefixSum;
}

int rangeSumQuery(const vector<int>& prefixSum, int left, int right) {
  return prefixSum[right + 1] - prefixSum[left];
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<int> prefixSum = buildPrefixSum(nums);

  cout << rangeSumQuery(prefixSum, 1, 2);  // Output: 5
  return 0;
}

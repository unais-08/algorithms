#include <bits/stdc++.h>
using namespace std;

// maximum sum of subarray of size k.
// [2,1,5,1,3,2]

int bruteForce(vector<int>& arr, int k) {
  int window = k;
  int n = arr.size();

  int maxSum = INT_MIN;

  for (int i = 0; i < n - 2; i++) {
    int sum = 0;
    for (int j = i; j < window; j++) {
      // cout << "[ " << arr[j] << " ]";
      sum += arr[j];
    }
    maxSum = max(maxSum, sum);
    window++;
    // cout << endl;
  }
  return maxSum;
}

int maxSumSubarray(vector<int>& arr, int k) {
  int n = arr.size();
  int left = 0, sum = 0, ans = 0;

  for (int right = 0; right < n; right++) {
    sum += arr[right];

    if (right - left + 1 == k) {
      ans = max(ans, sum);
      sum -= arr[left];
      left++;
    }
  }
  return ans;
}
int minSumSubarray(vector<int>& arr, int k) {
  int n = arr.size();
  int left = 0, sum = 0, ans = INT_MAX;

  for (int right = 0; right < n; right++) {
    sum += arr[right];

    if (right - left + 1 == k) {
      ans = min(ans, sum);
      sum -= arr[left];
      left++;
    }
  }
  return ans;
}

double findMaxAverage(vector<int>& nums, int k) {
  int n = nums.size();
  int left = 0;
  double sum = 0;
  double ans = INT_MIN;
  for (int right = 0; right < n; right++) {
    sum += nums[right];
    if (right - left + 1 == k) {
      ans = max(ans, sum / k);
      sum -= nums[left];
      left++;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {2, 1, 5, 1, 3, 2};

  int k = 3;
  cout << "max-sum: " << bruteForce(arr, k) << endl;
  cout << "max-sum: " << maxSumSubarray(arr, k) << endl;
  cout << "min-sum: " << minSumSubarray(arr, k) << endl;

  return 0;
}
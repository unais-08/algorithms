#include <bits/stdc++.h>
using namespace std;

int duplicateEleBruteForce(vector<int>& nums) {
  int n = nums.size();

  if (n <= 1) return -1;

  sort(nums.begin(), nums.end());  // O(n log n)

  for (int i = 1; i < n; i++) {
    if (nums[i] == nums[i - 1]) {
      return nums[i];  // duplicate found
    }
  }

  return -1;  // no duplicate
}

int duplicateEleCntBruteForce(vector<int>& nums) {
  int n = nums.size();
  int cnt = 0;
  if (n <= 1) return -1;

  sort(nums.begin(), nums.end());  // O(n log n)

  for (int i = 1; i < n; i++) {
    if (nums[i] == nums[i - 1]) {
      cnt++;  // duplicate found
    }
  }

  return cnt;  // no duplicate
}

// O(n)
int duplicateEle(vector<int>& nums) {
  unordered_set<int> st;

  for (int x : nums) {
    if (st.count(x)) {
      return x;  // duplicate found
    }
    st.insert(x);
  }

  return -1;
}

int duplicateEleCnt(vector<int>& nums) {
  unordered_set<int> st;
  int cnt = 0;
  for (int x : nums) {
    if (st.count(x)) {
      cnt++;  // duplicate found
    }
    st.insert(x);
  }

  return cnt;
}

int main() {
  vector<int> nums = {1, 8, 3, 4, 5, 6, 7, 8, 9};
  cout << duplicateEleBruteForce(nums);
  cout << duplicateEle(nums);
}
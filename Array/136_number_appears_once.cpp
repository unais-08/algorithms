#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR accumulates, cancels duplicates
        }
        return result;
    }

   public:
    int bruteForce(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            if (it.second == 1) return it.first;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v = {4,1,2,1,2};
    cout << s.bruteForce(v) << endl;

    return 0;
}
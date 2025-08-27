#include <bits/stdc++.h>
using namespace std;

// TC O(n)
// SC O(1)
class Solution {
   public:
    // O(2n+k) nearly O(n)
    void Brute(vector<int> &nums) {
        vector<int> temp;
        int count = 0;
        // O(n)
        if (nums.size() == 1) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                temp.push_back(nums[i]);
            }
        }
        // O(k)
        for (int i = (nums.size() - count) - 1; i < nums.size(); i++) {
            temp.push_back(0);
        }
        // O(n)
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }

    void moveZeroes(vector<int> &nums) {
        int j = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }
        if (j == INT_MIN) return;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    vector<int> v = {0, 1, 0, 3, 12};
    // vector<int> v = {0};

    // sample output: [1,3,12,0,0]
    Solution s;
    s.moveZeroes(v);
    for (auto &it : v) cout << it << " ";
    cout << endl;
}
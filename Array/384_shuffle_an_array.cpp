#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> original;
    int n;

   public:
    Solution(vector<int>& nums) {
        original = nums;
        n = nums.size();
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffleArr = original;
        // Fisher–Yates shuffle Algorithm
        // for (int i = n-1; i >=0; --i) {
        //     int randIdx = rand() % (i+1);
        //     swap(shuffleArr[i], shuffleArr[randIdx]);
        // }
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            swap(shuffleArr[i], shuffleArr[j]);
        }
        return shuffleArr;
    }
};

int main() {
    return 0;
}
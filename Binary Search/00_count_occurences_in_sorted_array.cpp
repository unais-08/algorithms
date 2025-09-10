#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countOccurrences(const vector<int>& arr, int target) {
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return ub - lb;
    }
};

int main() {
    Solution s;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 2, 2, 3, 4, 5}, 2},  // multiple occurrences
        {{1, 1, 1, 1, 1}, 1},        // all same element
        {{1, 2, 3, 4, 5}, 3},        // single occurrence
        {{1, 2, 4, 5, 6}, 3},        // not present in middle
        {{1, 2, 3, 4}, 10},          // target greater than all
        {{5, 6, 7, 8}, 1}            // target smaller than all
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        auto arr = testCases[i].first;
        int target = testCases[i].second;
        cout << "Test Case " << i + 1 << ": target = " << target << " → "
             << s.countOccurrences(arr, target) << "\n";
    }

    return 0;
}

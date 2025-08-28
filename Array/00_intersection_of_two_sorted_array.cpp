#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortedArrayIntersection(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();
        vector<int> ans;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                i++;
            } else if (b[j] < a[i]) {
                j++;
            } else {
                // Both are equal
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};


int main() {
    vector<int> num1 = {1, 2, 2, 5, 7, 10};
    vector<int> num2 = {2, 3, 3, 5, 6, 10, 12};
    Solution s;
    vector<int> ans = s.sortedArrayIntersection(num1, num2);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
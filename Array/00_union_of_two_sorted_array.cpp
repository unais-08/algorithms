#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> sortedArrayUnion(vector<int> &a, vector<int> &b) {
        int i = 0;
        int j = 0;

        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
            } else {
                if (ans.empty() || ans.back() != b[j]) {
                    ans.push_back(b[j]);
                }
                j++;
            }
        }
        while (i < n1) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        }
        while (j < n2) {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
        return ans;
    }
};

int main() {
    vector<int> num1 = {1, 2, 2, 5, 7, 10};
    vector<int> num2 = {2, 3, 3, 5, 6, 10, 12};
    Solution s;
    vector<int> ans = s.sortedArrayUnion(num1, num2);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
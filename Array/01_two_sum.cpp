#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};


// below is code for intuition building...
bool existenceCheck(vector<int> &nums, int target) {
    int sum;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            sum = 0;
            sum = nums[i] + nums[j];
            if (sum == target) {
                return true;
            }
        }
    }
    return false;
}

vector<int> indicesOfPair(vector<int> &nums, int target) {
    int sum;
    vector<int> ans(2, -1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            sum = 0;
            sum = nums[i] + nums[j];
            if (sum == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

vector<int> acturalNumPair(vector<int> &nums, int target) {
    int sum;
    vector<int> ans(2, -1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            sum = 0;
            sum = nums[i] + nums[j];
            if (sum == target) {
                ans[0] = nums[i];
                ans[1] = nums[j];
                return ans;
            }
        }
    }
    return ans;
}

int countNoOfPair(vector<int> &nums, int target) {
    int sum;
    vector<int> ans(2, -1);
    int pairCnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            sum = 0;
            sum = nums[i] + nums[j];
            if (sum == target) {
                pairCnt++;
            }
        }
    }
    return pairCnt;
}
vector<vector<int>> uniquePairs(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    unordered_set<int> seen;
    set<pair<int, int>> pairs;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) {
            int first = min(nums[i], complement);
            int second = max(nums[i], complement);
            pairs.insert({first, second});
        }
        seen.insert(nums[i]);
    }

    for (const auto &p : pairs) {
        ans.push_back({p.first, p.second});
    }

    return ans;
}
int main() {
    vector<int> v = {1, 5, 7, -1, 5};
    vector<int> v1 = {1, 2, 3, 2, 4, 3};
    int k = 5;
    // cout << (existenceCheck(v, k) ? "Found" : "Not Found") << endl;
    vector<int> ans = indicesOfPair(v, k);
    vector<int> ans2 = acturalNumPair(v, k);
    int ans3 = countNoOfPair(v, k);

    vector<vector<int>> ans4 = uniquePairs(v1, k);

    // cout << ans[0] << " " << ans[1] << endl;
    // cout << ans2[0] << " " << ans2[1] << endl;
    // cout << ans3 << endl;

    for (auto it : ans4) {
        cout << "[";
        for (int i = 0; i < it.size(); i++) {
            cout << it[i];
            if (i < it.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
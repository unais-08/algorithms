#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;

        int currentSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];

            // Check if we found a valid subarray
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[currentSum - k]);
            }

            // Store first occurrence only
            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
                prefixSumMap[currentSum] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> v = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << s.longestSubarray(v, k) << endl;

    return 0;
}

// 📝 Key Insight
/*
Use the Prefix Sum technique with a Hash Map to store the first occurrence of each prefix sum.

🧠 Algorithm Steps
Step 0: Initialization
Create an empty hash map prefixMap to store {prefix_sum: first_occurrence_index}

Initialize prefixMap[0] = -1 (crucial for subarrays starting from index 0)

Initialize currentSum = 0 and maxLength = 0

Step 1: Iterate through the array
For each element at index i from 0 to n-1:

Update current prefix sum: currentSum += nums[i]

Check if we found target sum directly:

If currentSum == K, update maxLength = max(maxLength, i + 1)

Check for complementary sum:

Calculate requiredSum = currentSum - K

If requiredSum exists in prefixMap:

Calculate subarray length: length = i - prefixMap[requiredSum]

Update maxLength = max(maxLength, length)

Store first occurrence:

If currentSum is NOT already in prefixMap:

Store prefixMap[currentSum] = i

Step 2: Return result
Return maxLength

🔍 Why This Works
Prefix Sum: Cumulative sum from start to current position

Hash Map: Remembers where each sum first appeared

currentSum - K = requiredSum: If requiredSum was seen before, the subarray between that index and
current index sums to K
*/
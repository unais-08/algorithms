#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC - O(1)

class Solution {
    public:
     int maxSubArray(vector<int>& nums) {
          // Kadane's Algorithm for finding maximum subarray sum
          int currentSubarraySum = 0;
          int maxSubarraySum = INT_MIN;
          
          for (int i = 0; i < nums.size(); i++) {
                // Add current element to the running subarray sum
                currentSubarraySum += nums[i];
                
                // Update maximum sum found so far
                maxSubarraySum = max(maxSubarraySum, currentSubarraySum);
                
                // If current sum becomes negative, reset it to 0
                // (start fresh subarray from next element)
                if (currentSubarraySum < 0) {
                     currentSubarraySum = 0;
                }
          }
          return maxSubarraySum;
     }

     void printMaxSubArray(vector<int>& nums) {
          // Kadane's Algorithm with subarray tracking
          int currentSubarraySum = 0;
          int maxSubarraySum = INT_MIN;
          
          // Track the indices of the maximum subarray
          int maxSubarrayStart = 0;
          int maxSubarrayEnd = 0;
          int currentSubarrayStart = 0;
          
          for (int i = 0; i < nums.size(); i++) {
                // Start new subarray when current sum is 0
                if (currentSubarraySum == 0) {
                     currentSubarrayStart = i;
                }

                // Add current element to the running subarray sum
                currentSubarraySum += nums[i];
                
                // Update maximum sum and subarray bounds if we found a better sum
                if (currentSubarraySum > maxSubarraySum) {
                     maxSubarraySum = currentSubarraySum;
                     maxSubarrayStart = currentSubarrayStart;
                     maxSubarrayEnd = i;
                }

                // If current sum becomes negative, reset it to 0
                // (prepare to start fresh subarray from next element)
                if (currentSubarraySum < 0) {
                     currentSubarraySum = 0;
                }
          }
          
          // Print results
          cout << "MAX SUM: " << maxSubarraySum << endl;
          cout << "Subarray: ";
          for (int i = maxSubarrayStart; i <= maxSubarrayEnd; i++) {
                cout << nums[i] << " ";
          }
          cout << endl;
     }
};

int main() {
     Solution solution;
     vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
     solution.printMaxSubArray(numbers);
     return 0;
}
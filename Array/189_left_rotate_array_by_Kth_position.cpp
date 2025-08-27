#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC O(n)+O(k)
    // SC O(1)
   public:
    void bruteForce(int* nums, int n, int d) {
        int k = d % n;
        // Extracting first K elements
        int temp[k];
        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        // shifting the elements to left

        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }
        // till we traverse whole array so complexity is O(k)+O(n-k)=O (n)
        // filling last empty position by roatated elements
        // O(k)
        for (int i = n - k; i < n; i++) {
            nums[i] = temp[i - (n - k)];
        }
    }

    /*
        TC O(n)
        O(d)+O(n−d)+O(n)
        O(2n)=O(n)
    */
    // SC O(1)
    void leftRotateByKthPlace(int* nums, int n, int d) {
        reverse(nums, nums + d);
        reverse(nums + d, nums + n);
        reverse(nums, nums + n);
    }
    void rightRotateByKthPlace(int* nums, int n, int d) {
        reverse(nums, nums + n);
        reverse(nums, nums + d);
        reverse(nums + d, nums + n);
    }
};

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(nums) / sizeof(nums[0]);

    Solution s;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.leftRotateByKthPlace(nums, n, 4);
    // s.rightRotateByKthPlace(nums,n,4);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}
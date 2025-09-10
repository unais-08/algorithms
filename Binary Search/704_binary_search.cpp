#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;  // PREVEVNT OVERFLOW CASE: INT_MAX + INT_MAX ;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

   public:
    int recursiveBinarySearch(vector<int> v, int target, int low, int high) {
        if (low > high) return -1;

        int mid = low + (high - low) / 2;

        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            return recursiveBinarySearch(v, target, mid + 1, high);
        else
            return recursiveBinarySearch(v, target, low, mid - 1);
    }
};

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution s;
    cout << "Present at index: " << s.search(v, 3) << endl;

    cout << "Present at index: " << s.recursiveBinarySearch(v, 3, 0, v.size() - 1) << endl;
    return 0;
}
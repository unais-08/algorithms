#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int subarrayWithSumK(vector<int> arr, int k) {
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;

    for (right; right < arr.size(); right++) {
        if (sum < k) {
            sum += arr[right];
            // mpp[sum]++;
        }

        if (sum == k) {
            cnt++;
            right++;
        }
        if (sum > k) {
            while (sum > k) {
                sum = sum - arr[left];
                left++;
            }
        }
    }
    return cnt;
}

int main() {
    cout << "Hello, World!" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int cnt = subarrayWithSumK(v, 9);
    cout << "Count: " << cnt << endl;
    return 0;
}



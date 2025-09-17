#include <bits/stdc++.h>
using namespace std;

// Function to find square root of a number using binary search
int sqrt(int n) {
    int ans = 1;  // Store the result
    int low = 1;  // Lower bound of search space
    int high = n; // Upper bound of search space
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate middle point to avoid overflow
        
        if (mid * mid <= n) {
            ans = mid;      // Update answer as we found a valid square root
            low = mid + 1;  // Search in right half for larger possible answer
        } else {
            high = mid - 1; // Search in left half as mid is too large
        }
    }

    return ans;  // Return the largest integer whose square is <= n
}

int main() {
    int root = sqrt(625);  // Find square root of 625
    cout << root << endl;  // Output: 25
    return 0;
}
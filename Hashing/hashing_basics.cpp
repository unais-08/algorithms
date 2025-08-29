#include <bits/stdc++.h>
using namespace std;

class ArrayHashOperations {
   public:
    // Check if element exists using frequency array
    bool existsUsingFrequencyArray(const vector<int>& arr, int target) {
        if (arr.empty()) return false;

        int maxElement = *max_element(arr.begin(), arr.end());  // STL: finds maximum element
        if (target > maxElement || target < 0) return false;

        vector<int> frequency(maxElement + 1, 0);
        for (int element : arr) {
            frequency[element]++;
        }

        return frequency[target] > 0;
    }
 
    // Check if element exists using hash set
    bool existsUsingHashSet(const vector<int>& arr, int target) {
        unordered_set<int> elementSet(arr.begin(), arr.end());  // STL: O(1) average lookup
        return elementSet.find(target) != elementSet.end();
    }

    // Print unique elements in sorted order
    void printUniqueElementsSorted(const vector<int>& arr) {
        set<int> uniqueElements(arr.begin(), arr.end());  // STL: automatically sorted and unique
        for (const auto& element : uniqueElements) {
            cout << element << " ";
        }
        cout << endl;
    }

    // Count frequency using array-based hashing
    int getFrequencyUsingArray(const vector<int>& arr, int target) {
        if (arr.empty()) return 0;

        int maxElement = *max_element(arr.begin(), arr.end());
        if (target > maxElement || target < 0) return 0;

        vector<int> frequency(maxElement + 1, 0);
        for (int element : arr) {
            frequency[element]++;
        }

        return frequency[target];
    }

    // Count frequency using hash map
    int getFrequencyUsingHashMap(const vector<int>& arr, int target) {
        unordered_map<int, int> frequencyMap;

        for (int element : arr) {
            frequencyMap[element]++;  // STL: auto-creates entry if not exists
        }

        return frequencyMap[target];  // Returns 0 if key doesn't exist
    }

    // Find first non-repeating element using frequency array
    int findFirstUniqueElement(const vector<int>& arr) {
        if (arr.empty()) return -1;

        int maxElement = *max_element(arr.begin(), arr.end());
        vector<int> frequency(maxElement + 1, 0);

        // Count frequencies
        for (int element : arr) {
            frequency[element]++;
        }

        // Find first element with frequency 1 in original order
        for (int element : arr) {
            if (frequency[element] == 1) {
                return element;
            }
        }

        return -1;  // No unique element found
    }
};

int main() {
    vector<int> testArray = {1, 1, 1, 1, 2, 3, 5, 2, 4, 5};
    vector<int> uniqueTestArray = {1, 2, 2, 1, 3, 4, 3};

    ArrayHashOperations operations;

    // Test frequency counting
    cout << "Frequency of 5: " << operations.getFrequencyUsingArray(testArray, 5) << endl;

    // Test finding first unique element
    cout << "First unique element: " << operations.findFirstUniqueElement(uniqueTestArray) << endl;

    return 0;
}

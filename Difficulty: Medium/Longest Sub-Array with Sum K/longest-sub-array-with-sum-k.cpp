//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
         unordered_map<int, int> prefixMap; // To store prefix sums and their indices
        int prefixSum = 0;                 // Running prefix sum
        int maxLength = 0;                 // Maximum length of subarray

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i]; // Update the prefix sum

            // Check if prefixSum is equal to k
            if (prefixSum == k) {
                maxLength = i + 1;
            }

            // Check if (prefixSum - k) exists in the map
            if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
                int length = i - prefixMap[prefixSum - k];
                maxLength = max(maxLength, length);
            }

            // Store the prefix sum in the map if it is not already present
            if (prefixMap.find(prefixSum) == prefixMap.end()) {
                prefixMap[prefixSum] = i;
            }
        }

        return maxLength;
    // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
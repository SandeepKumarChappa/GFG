//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        
               int maxSum = arr[0]; // Initialize maxSum with the first element
        int currentSum = arr[0]; // Initialize currentSum with the first element

        for (int i = 1; i < arr.size(); i++) {
            // Update currentSum: either extend the current subarray or start a new one
            currentSum = max(arr[i], currentSum + arr[i]);
            // Update maxSum to store the maximum subarray sum encountered so far
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends
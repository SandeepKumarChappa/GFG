//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        
         int n = arr.size();
        if (n <= 1) return 0; // If the array has one element, no jump is needed.
        if (arr[0] == 0) return -1; // If the first element is 0, we can't move anywhere.

        int jumps = 1;         // At least one jump is needed to start.
        int farthest = arr[0]; // The farthest we can currently reach.
        int currentEnd = arr[0]; // The end of the current jump range.

        for (int i = 1; i < n; i++) {
            // If we have reached the last element, return the number of jumps.
            if (i == n - 1) return jumps;

            // Update the farthest we can reach.
            farthest = max(farthest, i + arr[i]);

            // If we reach the end of the current range, we need another jump.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // If the currentEnd is less than or equal to the current index, it's not possible to proceed.
                if (currentEnd <= i) return -1;
            }
        }

        return -1; // If we exit the loop without reaching the end, return -1.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
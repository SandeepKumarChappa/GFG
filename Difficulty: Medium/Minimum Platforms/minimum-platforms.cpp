//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;

        // Traverse through all events
        while (i < n && j < n) {
            // If the next event is an arrival
            if (arr[i] <= dep[j]) {
                platforms++;  // One more platform is needed
                i++;  // Move to next arrival
            } 
            // If the next event is a departure
            else {
                platforms--;  // A platform is freed
                j++;  // Move to next departure
            }
            
            // Update the maximum platforms needed
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;// Your code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// User function Template for C++
class Solution {
  public:
    // Function to check if the given distance is feasible
    bool isFeasible(vector<int> &stalls, int k, int minDist) {
        int cowsPlaced = 1; // Place the first cow
        int lastPos = stalls[0]; // Position of the first stall

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                cowsPlaced++;
                lastPos = stalls[i]; // Update the position of the last placed cow
            }
            if (cowsPlaced == k) return true; // If all cows are placed successfully
        }

        return false; // Couldn't place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Sort the stalls to work with positions in order
        sort(stalls.begin(), stalls.end());

        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls[0]; // Maximum possible distance
        int result = 0;

        // Binary search for the maximum minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isFeasible(stalls, k, mid)) {
                result = mid; // Update result if feasible
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Reduce the distance
            }
        }

        return result;
    }
};



// class Solution {
//   public:

//     int aggressiveCows(vector<int> &stalls, int k) {

//         // Write your code here
//     }
// };

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
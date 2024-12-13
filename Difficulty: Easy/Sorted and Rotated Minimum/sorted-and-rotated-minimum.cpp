//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        
//         #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            // Check if the mid is in the smaller segment
            if (arr[mid] <= arr[high]) {
                high = mid; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        }
        // low and high converge to the minimum element
        return arr[low];
    }
};

// int main() {
//     Solution sol;
//     vector<int> arr1 = {5, 6, 1, 2, 3, 4};
//     vector<int> arr2 = {3,

        
        
//         // complete the function here
//     }
// };

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
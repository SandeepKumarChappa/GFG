//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class Solution {
//   public:
//     int search(vector<int>& arr, int key) {
//         // complete the function here
//     }
// };

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key) {
                return mid; // Key found
            }

            // Determine if the left half is sorted
            if (arr[left] <= arr[mid]) {
                // Check if key lies in the left half
                if (arr[left] <= key && key < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Right half must be sorted
                // Check if key lies in the right half
                if (arr[mid] < key && key <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1; // Key not found
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
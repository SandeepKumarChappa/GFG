//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    //int kthSmallest(vector<int> &arr, int k) {
        int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Pivot element
        int i = low - 1;       // Pointer for smaller elements
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[high]);
        return i + 1; // Return the position of the pivot
    }
    
    // Quickselect function to find kth smallest element
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pivotIndex = partition(arr, low, high);

            // Check if the pivotIndex is the k-1th element
            if (pivotIndex == k - 1) {
                return arr[pivotIndex];
            } else if (pivotIndex > k - 1) {
                // Recur on the left of pivot
                return quickSelect(arr, low, pivotIndex - 1, k);
            } else {
                // Recur on the right of pivot
                return quickSelect(arr, pivotIndex + 1, high, k);
            }
        }
        return -1; // Invalid case
    }

    // Main function to find kth smallest element
    int kthSmallest(vector<int>& arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k);

        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
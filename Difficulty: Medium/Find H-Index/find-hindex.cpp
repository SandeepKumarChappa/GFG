//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends






class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // Sort citations in descending order
        sort(citations.rbegin(), citations.rend());
        
        // Iterate through the sorted citations
        for (int i = 0; i < citations.size(); i++) {
            // If the citation count is less than i + 1, return i
            if (citations[i] < i + 1) {
                return i;
            }
        }
        
        // If no condition fails, return the total number of citations
        return citations.size();
    }
};






//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
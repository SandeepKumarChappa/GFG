//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        
        // ic:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // Ensure a[] is the smaller array
        if (a.size() > b.size()) return kthElement(b, a, k);
        
        int n1 = a.size();
        int n2 = b.size();
        int low = max(0, k - n2), high = min(k, n1); // Binary search boundaries
        
        while (low <= high) {
            int cut1 = (low + high) / 2; // Elements taken from a
            int cut2 = k - cut1;         // Elements taken from b
            
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1]; // Left max of a
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1]; // Left max of b
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];    // Right min of a
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];    // Right min of b
            
            // Check if we have found the correct partition
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2); // kth element is the max of the left side
            } else if (l1 > r2) {
                high = cut1 - 1; // Move left in a
            } else {
                low = cut1 + 1;  // Move right in a
            }
        }
        return -1; // This line should not be reached

        
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
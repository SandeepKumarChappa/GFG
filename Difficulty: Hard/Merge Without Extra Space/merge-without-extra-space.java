//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases

        while (t-- > 0) {
            String arr1[] = br.readLine().trim().split(" ");
            String arr2[] = br.readLine().trim().split(" ");

            int a[] = new int[arr1.length];
            int b[] = new int[arr2.length];

            for (int i = 0; i < a.length; i++) a[i] = Integer.parseInt(arr1[i]);
            for (int i = 0; i < b.length; i++) b[i] = Integer.parseInt(arr2[i]);

            Solution ob = new Solution();
            ob.mergeArrays(a, b);

            StringBuffer str = new StringBuffer();
            for (int i = 0; i < a.length; i++) {
                str.append(a[i] + " ");
            }
            System.out.println(str);
            str = new StringBuffer();
            for (int i = 0; i < b.length; i++) {
                str.append(b[i] + " ");
            }
            System.out.println(str);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// class Solution {
//     // Function to merge the arrays.
//     public void mergeArrays(int a[], int b[]) {
//         // code here
    // }
// }

class Solution {
    // Function to merge the arrays.
    public void mergeArrays(int a[], int b[]) {
        int n = a.length; // Length of array a
        int m = b.length; // Length of array b
        
        int i = n - 1; // Pointer for the end of array a
        int j = 0;     // Pointer for the start of array b

        // Step 1: Swap elements if needed
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                // Swap elements to ensure smallest in `b[]` and largest in `a[]`
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
            }
            i--; // Move backward in `a[]`
            j++; // Move forward in `b[]`
        }

        // Step 2: Sort both arrays to maintain sorted order
        Arrays.sort(a);
        Arrays.sort(b);
    }
}


//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
    
    
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

struct node* push(struct node* head, int new_data) {
    struct node* new_node = new node(new_data);
    new_node->next = head;
    head = new_node;
    return head;
}


class Solution {
  public:
  
  struct node* reverseIt(struct node* head, int k) {
        // Initialize pointers
        struct node *current = head;
        struct node *prev = NULL;
        struct node *next = NULL;
        int count = 0;

        // Reverse k nodes of the linked list
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // If there are more nodes left to reverse
        if (next != NULL) {
            head->next = reverseIt(next, k);
        }

        // Return the new head of the reversed group
        return prev;
    }
};
//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return (0);
}

// } Driver Code Ends
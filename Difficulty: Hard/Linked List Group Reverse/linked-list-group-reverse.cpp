//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *rev(Node *head){
        Node *curr = head, *prev = nullptr, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k == 1)  
            return head;
            
        int k1;
        Node *ans=NULL, *curr=head, *nxt=head, *ansPtr;
        
        while(nxt){
            curr = nxt;
            Node *tempHead = curr;
            k1 = k;
            while(--k1 && curr->next){
                curr = curr->next;
            }
            
            nxt = curr->next;
            curr->next = NULL;
            
            if(ans == NULL){
                ans = rev(tempHead);
                ansPtr = ans;
            }
            else{
                ansPtr->next = rev(tempHead);
            }
            
            while(ansPtr->next)
                ansPtr = ansPtr->next;
                
            //curr->next = nxt;
        }
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
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
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
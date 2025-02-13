//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *rev(Node *head){
        if(!head || !head->next)
            return head;
        
        Node *prev = NULL;
        Node *nxt = head->next;
        while(head){
            head->next = prev;
            prev = head;
            head = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        return prev;
    }
    
    Node *reverse(Node *head, int k) {
        // code here
        Node *ptr = head;
        Node *follow = NULL;
        while(k--){
            follow = ptr;
            ptr = ptr->next;
        }
        follow->next = NULL;
        
        head = rev(head);
        ptr = rev(ptr);
        
        follow = head;
        while(follow->next){
            follow = follow->next;
        }
        
        follow->next = ptr;
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
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
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
        cout << "~" << endl;
    }
}
// } Driver Code Ends
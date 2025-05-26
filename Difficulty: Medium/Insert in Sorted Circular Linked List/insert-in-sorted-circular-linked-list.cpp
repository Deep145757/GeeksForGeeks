/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *nnd = new Node(data);
        if(data < head->data){
            nnd->next = head;
            Node *ptr = head;
            
            while(ptr->next != head){
                ptr = ptr->next;
            }
            
            ptr->next = nnd;
            return nnd;
        }
        
        Node *ptr = head->next, *prev=head;
        while(ptr->data < data && ptr!=head){
            prev = ptr;
            ptr = ptr->next;
        }
        
        prev->next = nnd;
        nnd->next = ptr;
        
        return head;
    }
};
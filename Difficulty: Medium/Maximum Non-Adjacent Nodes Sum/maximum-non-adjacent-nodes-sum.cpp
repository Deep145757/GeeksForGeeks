/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int>travel(Node *root){      //1. using Node 2.using childs
        if(!root)
            return {0, 0};
            
        vector<int>l={0, 0};
        vector<int>r = l;
        vector<int>ans = l;
        
        if(root->left)
            l = travel(root->left);
        if(root->right)
            r = travel(root->right);
            
        return {root->data+l[1]+r[1], max(l[0], l[1]) +max(r[0], r[1])};
    }
  
    int getMaxSum(Node *root) {
        // code here
        vector<int>p = travel(root);
        return max(p[0], p[1]);
    }
};
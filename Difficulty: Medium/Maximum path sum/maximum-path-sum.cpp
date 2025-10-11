/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int maxSum = INT_MIN;
  
    int traverse(Node *root){
        if(!root)
            return 0;
        int l = traverse(root->left);
        int r = traverse(root->right);
        
        r = max(r, 0);
        l = max(l, 0);
        
        maxSum = max(maxSum, r+l+root->data);
        return max(r, l) + root->data;
    }
    
    
    int findMaxSum(Node *root) {
        // code here
        traverse(root);
        return maxSum;
    }
};
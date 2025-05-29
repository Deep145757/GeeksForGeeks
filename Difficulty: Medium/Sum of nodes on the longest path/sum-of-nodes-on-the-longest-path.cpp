/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<int> f(Node *root){
        if(!root->right && !root->left)
            return {0, root->data};
            
        vector<int>l = {0,0};
        vector<int>r = l;
        
        if(root->right){
            r = f(root->right);
            r[0]++;
            r[1] += root->data;
        }
        
        if(root->left){
            l = f(root->left);
            l[0]++;
            l[1] += root->data;
        }
        if(l[0]>r[0])
            return l;
        else if(l[0] == r[0])
            return (l[1]>r[1]) ? l : r;
        return r;
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        vector<int>a = f(root);
        return a[1];
    }
};
class Solution {
  public:
    vector<int>f(int s , int e , vector<int>&preorder){
        if(s == e) return {preorder[s]} ;
        if(s > e) return {} ;
        
        int curr = preorder[s] ;
        int i = s + 1 ; 
        while(i <= e && preorder[i] < curr) i ++ ;
        
        vector<int>leaf_left = f(s + 1 , i - 1 , preorder) ;
        vector<int>leaf_right = f(i , e , preorder ) ;
        
        for(int i : leaf_right) leaf_left.push_back(i) ;
        
        return leaf_left ;
    }
    
    vector<int> leafNodes(vector<int>& preorder) {
        int n = preorder.size() ;
        return f(0 , n - 1 , preorder) ;
    }
};
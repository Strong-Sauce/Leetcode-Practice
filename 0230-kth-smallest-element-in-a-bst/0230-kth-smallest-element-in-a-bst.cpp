/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    void sol(TreeNode* root, int &k){
        if(!root ||  k==0) return ;
        sol(root->left, k);
        k--;
        if(k == 0) ans = root->val;
        sol(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        sol(root, k);
        return ans; 
    }
};
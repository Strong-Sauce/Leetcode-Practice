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
    int maxi = INT_MIN;
    int getmax(TreeNode* root){
        if(!root) return 0;
        int l = getmax(root->left);
        int r = getmax(root->right);
        int sum = root->val + r + l;
        int lsum = root->val + l;
        int rsum = root->val + r;
        maxi = max(maxi, max(root->val, max(sum, max(lsum, rsum))));
        return max(root->val, root->val + max(r, l));
    }
    int maxPathSum(TreeNode* root) {
        int sum = getmax(root);
        return maxi;
    }
};

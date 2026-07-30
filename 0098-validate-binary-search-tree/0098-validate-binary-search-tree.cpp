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
    void getIn(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        getIn(root->left, inorder);
        inorder.push_back(root->val);
        getIn(root->right, inorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        getIn(root, inorder);
        for(int i=0; i<inorder.size()-1; i++){
            if(inorder[i] >=  inorder[i+1]) return 0;
        }
        return 1;
    }
};
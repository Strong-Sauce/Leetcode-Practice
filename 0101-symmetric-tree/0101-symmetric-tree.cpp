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
    bool check(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL) return 1;
        if(node1==NULL && node2!=NULL ||  node1!=NULL && node2==NULL) return 0;
        if(node1->val != node2->val) return 0;

        return (check(node1->right, node2->left) && check(node1->left, node2->right));
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
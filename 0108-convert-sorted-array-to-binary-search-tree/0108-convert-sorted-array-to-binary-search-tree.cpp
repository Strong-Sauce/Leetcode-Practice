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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;
        int i = n/2;
        TreeNode* root = new TreeNode(nums[i]);

        vector<int> left;
        for(int a=0; a<i; a++) left.push_back(nums[a]);
        root->left = sortedArrayToBST(left);

        vector<int> right;
        for(int a=i+1; a<nums.size(); a++) right.push_back(nums[a]);
        root->right = sortedArrayToBST(right);

        return root;
    }
};
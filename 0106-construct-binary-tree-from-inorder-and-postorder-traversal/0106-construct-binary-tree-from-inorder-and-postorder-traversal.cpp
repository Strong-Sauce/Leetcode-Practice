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
    unordered_map<int , int> mp;
    TreeNode* sol(vector<int>& inorder, vector<int>& post, int &postpos, int s, int e){
        if(s > e) return NULL;

        int currval = post[postpos--];
        TreeNode* root = new TreeNode(currval);
        if(s==e) return root;

        int pos = mp[currval];
        root->right = sol(inorder, post, postpos, pos+1, e);
        root->left = sol(inorder, post, postpos, s, pos-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        int n = post.size();
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        int postpos = n-1;
        return sol(inorder, post, postpos, 0, n-1);
    }
};
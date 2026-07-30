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
    unordered_map<int , int > mp;
    int i = 0;
    TreeNode* sol(vector<int>& pre, vector<int>& in, int s, int e){
        if(s > e) return NULL;
        
        int currval = pre[i++];
        TreeNode* root = new TreeNode(currval);
        if(s==e) return root;//dont need this but reduces steps

        int pos = mp[currval];
        
        root->left = sol(pre, in, s, pos-1);
        root->right = sol(pre, in, pos+1, e);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int j=0; j<in.size(); j++){
            mp[in[j]] = j;
        }
        return sol(pre, in, 0, in.size()-1);
    }
};
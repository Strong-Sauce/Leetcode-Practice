/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int rval = root.val, pval = p.val, qval = q.val;
        if(rval>pval && rval>qval) return lowestCommonAncestor(root.left, p, q);
        else if(rval<pval && rval<qval) return lowestCommonAncestor(root.right, p, q);
        return root;
    }
}
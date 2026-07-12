/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        boolean l = true, r = true;
        if(root.left != null){
            TreeNode temp = root.left;
            while(temp.right != null) temp = temp.right;
            if(temp.val < root.val) l = isValidBST(root.left);
            else return false;
        }
        if(root.right != null){
            TreeNode temp = root.right;
            while(temp.left != null) temp = temp.left;
            if(temp.val > root.val) r = isValidBST(root.right);
            else return false;
        }
        return l&r;
    }
}
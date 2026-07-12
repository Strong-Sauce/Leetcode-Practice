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
    public void insert(TreeNode root, int i){
        int val = root.val;
        if(i>val) {
            if(root.right != null) insert(root.right, i);
            else root.right = new TreeNode(i);
        }
        else{
            if(root.left != null) insert(root.left, i);
            else root.left = new TreeNode(i);
        }
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.length; i++){
            insert(root, preorder[i]);
        }
        return root;
    }
}
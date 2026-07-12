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
    public void inorder(TreeNode root, List<Integer> inorder){
        if(root.left != null) inorder(root.left, inorder);
        inorder.add(root.val);
        if(root.right != null) inorder(root.right, inorder);
    }
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> inorder = new ArrayList<>();
        inorder(root, inorder);

        int l=0, r=inorder.size()-1;
        while(l<r){
            int sum = inorder.get(l) + inorder.get(r);
            if(sum == k) return true;
            else if(sum > k) r--;
            else l++;
        }
        return false;
    }
}
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
    static class Info {
        boolean isBST;
        int sum;
        int minVal;
        int maxVal;

        public Info(boolean isBST, int sum, int min, int max) {
            this.isBST = isBST;
            this.sum = sum;
            this.minVal = min;
            this.maxVal = max;
        }
    }

    static int maxSum = 0;

    public static Info largestBST(TreeNode root) {
        if (root == null) {
            return new Info(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        Info left = largestBST(root.left);
        Info right = largestBST(root.right);

        if (left.isBST && right.isBST && root.val > left.maxVal && root.val < right.minVal) {
            int currSum = left.sum + right.sum + root.val;
            maxSum = Math.max(maxSum, currSum);
            return new Info(true, currSum, Math.min(root.val, left.minVal), Math.max(root.val, right.maxVal));
        }

        // Not a BST
        return new Info(false, 0, 0, 0);
    }

    public int maxSumBST(TreeNode root) {
        maxSum = 0;
        largestBST(root);
        return maxSum;
    }
}
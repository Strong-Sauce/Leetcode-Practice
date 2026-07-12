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
class BSTIterator {
    Queue<Integer> q;
    public BSTIterator(TreeNode root) {
        q=new LinkedList<>();
        initQueue(root);
    }
    public  void initQueue(TreeNode root){
        if(root==null) return;
        initQueue(root.left);
        q.offer(root.val);
        initQueue(root.right);
    }
    public int next() {
        return q.poll();
    }
    
    public boolean hasNext() {
        return q.isEmpty() ? false : true;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
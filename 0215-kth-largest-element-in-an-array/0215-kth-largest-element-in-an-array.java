class Solution {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    public int findKthLargest(int[] nums, int k) {
        for (int i:nums){
            pq.offer(i);
            if(pq.size() > k) pq.poll();
        }
        return pq.poll();
    }
}
class Solution {
    public boolean isBipartite(int[][] graph) {
        int v = graph.length;
        int[] colour = new int[v];

        Deque<Integer> dq = new ArrayDeque<>();
        for(int i=0; i<v; i++){
            if(colour[i] == 0){
                dq.offer(i);
                colour[i] = 1;
                colour[i] = 1;
            }
            while(!dq.isEmpty()){
                int front = dq.poll();
                for(int nbr:graph[front]){
                    if(colour[nbr] == 0){
                        dq.offer(nbr);
                        colour[nbr] = colour[front]==1 ? 2 : 1;
                        colour[nbr] = colour[front]==1 ? 2 : 1;
                    }
                    else if(colour[nbr] == colour[front]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
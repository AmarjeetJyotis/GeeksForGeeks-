// User function Template for Java

class Solution{
    public long largesSumCycle(int N, int Edge[]){
       int[] prefixSum = new int[N];
       int[] visited = new int[N];
       Arrays.fill(visited, -1);
       
       int cycleLabel = 0;
       int ans = -1;
       for(int i = 0; i < N; i++) {
           int dst = i;
           int currSum = dst;
           int prev = -1;
           prefixSum[dst] = dst;
           while(dst != -1 && visited[dst] == -1) {
                visited[dst] = cycleLabel;
                prev = dst;
                dst = Edge[dst];
                if(dst != -1 && visited[dst] == -1) {
                    currSum += dst;
                    prefixSum[dst] = currSum;
                } else if (dst != -1 && visited[dst] != -1) {
                    if(visited[dst] == cycleLabel) {
                        ans = Math.max(ans, prefixSum[prev]-prefixSum[dst]+dst);
                        dst = -1;
                        
                    } 
                    break;
                }
           }
          
           cycleLabel++;
       }
       
       return ans;
    }
}

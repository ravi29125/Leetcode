class Solution {
    public int findChampion(int n, int[][] edges) {
        int m=edges.length;
        int[] ans = new int[n];
        for(int i=0;i<m;i++){
            ans[edges[i][1]]--;
        }//for(int k : ans)System.out.println(k);
        int index=0;
        for(int i=1;i<n;i++){
            if(ans[i]>ans[index]){
                index=i;
            }
        }
        int cnt=0;
        for(int i:ans){
            if(i==ans[index])cnt+=1;
            if(cnt>1)return -1;
        }
        return index;
    }
}
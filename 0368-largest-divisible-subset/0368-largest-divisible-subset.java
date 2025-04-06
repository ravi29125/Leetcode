class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        List<Integer> ls=new ArrayList<>();
        int[] dp=new int[n],pre=new int[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
            pre[i]=-1;
        }
        int mx=0,ind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                ind=i;
            }
        }
        for(int i=ind;i>-1;i=pre[i]){
            ls.add(nums[i]);
        }
        return ls;
    }
}
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int t1=target,t2=-target;
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(dp[i]==INT_MIN)continue;
            for(int j=i+1;j<n;j++){
                int val=nums[j]-nums[i];
                if(val>=t2 && val<=t1){
                    dp[j]=max(dp[i]+1,dp[j]);
                }
            }
        }
        return dp[n-1]==INT_MIN?-1:dp[n-1];
    }
};
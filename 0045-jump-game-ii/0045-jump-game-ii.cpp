class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<long> dp(n,INT_MAX);
        dp[0]=0;
        int j=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n && j<=nums[i]+i;j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        //for(int i:dp)cout<<i<<" ";
        return dp[n-1];
    }
};
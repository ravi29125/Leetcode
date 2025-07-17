class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k,1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int val=(nums[i]+nums[j])%k;
                dp[i][val]=max(dp[j][val]+1,dp[i][val]);
                ans=max(ans,dp[i][val]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;
        if(sum%2==1) return false;
        int val=sum/2;
        vector<bool> dp(val+1,false);
        dp[0]=true;
        for(int i:nums){
            for(int j=val;j>=i;j--){
                dp[j]=dp[j] || dp[j-i];
            }
        }
        return dp[val];
    }
};
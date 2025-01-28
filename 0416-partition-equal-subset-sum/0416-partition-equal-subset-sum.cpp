class Solution {
    bool help(int n,int i,vector<int>& nums,int s1,int s2){
        if(i==n){
            return s1==s2;
        }return help(n,i+1,nums,s1+nums[i],s2) || help(n,i+1,nums,s1,nums[i]+s2); 
    }
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
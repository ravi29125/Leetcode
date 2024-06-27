class Solution {
    vector<int> nums;
    vector<vector<vector<long long>>>dp;
    long long help(int i,int st,int sign,int n){
        long long ans=-1e15;
        if(i==n)return 0;
        if(dp[i][st][sign]!=-1e15)return dp[i][st][sign];
        if(st==0){
            ans=max(ans,nums[i]+help(i+1,1,sign,n));
        }else{
            if(sign){
                ans=max(ans,nums[i]+help(i+1,1,1-sign,n));
            }else{
                ans=max(ans,-nums[i]+help(i+1,1,1-sign,n));
            }
            ans=max(ans,help(i,0,0,n));
        }
        return dp[i][st][sign]=ans;
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        this->nums=nums;
        this->dp=vector<vector<vector<long long>>>(n+1,vector<vector<long long>>(2,vector<long long>(2,-1e15)));
        return help(0,0,0,n);
    }
};
class Solution {
    vector<int> dp;
    bool help(vector<int>&nums,int i){
        if(i<0 || i>=nums.size())return false;
        if(dp[i]==1 || nums[i]==0)return true;
        else if(dp[i]==0) return false;
        dp[i]=0;
        dp[i]=help(nums,i+nums[i]) || help(nums,i-nums[i]);
        return dp[i];
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        dp=vector<int>(n,-1);
        return help(arr,start);
    }
};
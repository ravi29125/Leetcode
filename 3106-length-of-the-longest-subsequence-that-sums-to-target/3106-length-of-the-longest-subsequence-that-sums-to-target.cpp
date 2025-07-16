class Solution {
    int ans;
    map<pair<int,pair<int,int>>,int> mp;
    int help(vector<int>& nums,int i,int target,int curr,int cnt){
        if(mp.count({i,{cnt,curr}})) return mp[{i,{cnt,curr}}];
        if(i==0){
            if(curr==target) return 0;
            else return -1;
        }else{
            int val=help(nums,i-1,target,curr,cnt);
            if(curr+nums[i-1]<= target){
                int b=help(nums,i-1,target,curr+nums[i-1],cnt+1);
                if(b!=-1){
                    val=max(val,b+1);
                }
            }
            return mp[{i,{cnt,curr}}]=val;
        }return -1;
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int t) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1] && dp[i-1][j-nums[i-1]]!=-1){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-nums[i-1]]+1);
                }
            }
        }return dp[n][t];
    }
};
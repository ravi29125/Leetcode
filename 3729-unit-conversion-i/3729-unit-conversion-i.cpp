class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& con) {
        //sort(con.begin(),con.end());
        long n=con.size(),mod=1e9+7;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=1;
        for(int i=0;i<n;i++){
            long val=con[i][2];
            val*=dp[con[i][0]];
            val%=mod;
            dp[con[i][1]]=min(dp[con[i][1]],(int)val);
        }return dp;
    }
};
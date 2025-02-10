class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=vector<int>(i+1,INT_MAX);
        }
        dp[0][0]=t[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<dp[i].size();j++){
                //dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(j >= 0 && j < dp[i-1].size())
                dp[i][j]=min(dp[i][j],dp[i-1][j]+t[i][j]);
                if(j-1 >= 0 && j-1 < dp[i-1].size())
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+t[i][j]);
            }
        }return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
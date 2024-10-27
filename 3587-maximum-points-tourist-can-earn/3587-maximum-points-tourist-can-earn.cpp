class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int i=1;i<=k;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    dp[i][j]=max(dp[i-1][k]+travelScore[k][j],dp[i][j]);
                }
                dp[i][j]=max(dp[i-1][j]+stayScore[i-1][j],dp[i][j]);
                //cout<<i-1<<" "<<j<<" ";
            }
        }
        //for(auto p:dp)for(auto o:p)cout<<o<<" ";
        return *max_element(dp[k].begin(),dp[k].end());
    }
};
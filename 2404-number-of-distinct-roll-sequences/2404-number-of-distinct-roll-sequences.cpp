class Solution {
public:
    int distinctSequences(int n) {
        int val=6,mod=1e9+7;
        vector<vector<int>> dp(val+1,vector<int>(val+1,0));
        for(int i=1;i<=val;i++)dp[0][i]=1;
        for(int p=1;p<n;p++){
            vector<vector<int>> tp(val+1,vector<int>(val+1,0));
            for(int i=0;i<=val;i++){
                for(int j=1;j<=val;j++){
                    for(int k=1;k<=val;k++){
                        if(__gcd(k,j)!=1 || k==j || k==i)continue;
                        tp[j][k]=(tp[j][k]+dp[i][j])%mod;
                    }
                }
            }
            dp=tp;
        }
        long cnt=0;
        for(auto k:dp){
            for(auto j:k){
                cnt=(cnt+j)%mod;
            }
        }return cnt;
    }
};
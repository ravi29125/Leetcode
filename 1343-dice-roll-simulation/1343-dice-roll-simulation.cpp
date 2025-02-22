class Solution {
    const int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int help(int n,vector<int>& rollMax,int pre,int cnt){
        if(n==0) return 1;
        if(dp[n][pre][cnt]!=-1) return dp[n][pre][cnt];
        long ans=0;
        for(int i=0;i<rollMax.size();i++){
            if(rollMax[i]>0){
                if(i+1 == pre){
                    if(cnt<rollMax[i])
                    ans=(ans+help(n-1,rollMax,i+1,cnt+1))%mod;
                }else{
                    ans=(ans+help(n-1,rollMax,i+1,1))%mod;
                }
            }
        }return dp[n][pre][cnt]=ans;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(rollMax.size()+1,vector<int>(16,-1)));
        return help(n,rollMax,0,1);
    }
};
class Solution {
    int mod=1e9+7;
    vector<long long> fact,infact;
    long long modPow(long long  n,long long  e){
        long long res=1;
        while(e){
            if(e%2==1){
                res=(res*n)%mod;
            }
            n=(n*n)%mod;
            e=e>>1;
        }return res;
    }
    int help(int n,int r){
        if (r<0||r>n) return 0;
        return (((fact[n]*infact[r])%mod)*infact[n-r])%mod;
    }
public:
    int idealArrays(int n, int maxValue) {
        int m=n+21;
        fact=vector<long long>(m+1,0);
        infact=vector<long long>(m+1,0);
        fact[0]=1;
        for(int i=1;i<=m;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        infact[m]=modPow(fact[m],mod-2);
        for(int i=m-1;i>-1;i--){
            infact[i]=(infact[i+1]*(i+1))%mod;
        }
        long sum=0;
        vector<vector<int>> dp(maxValue+1,vector<int>(21,0));
        for(int i=1;i<=maxValue;i++){
            dp[i][1]=1;
            for(int j=i+i;j<=maxValue;j+=i){
                for(int k=0;k<20;k++){
                    dp[j][k+1]=(dp[j][k+1]+dp[i][k])%mod;
                }
            }
        }
        long val=0;
        for(int i=1;i<=maxValue;i++){
            for(int j=1;j<21;j++){
                if(dp[i][j]==0)continue ;
                val=help(n-1,j-1);
                val=(val*dp[i][j])%mod;
                sum=(sum+val)%mod;
            }
        }
        return sum;
    }
};
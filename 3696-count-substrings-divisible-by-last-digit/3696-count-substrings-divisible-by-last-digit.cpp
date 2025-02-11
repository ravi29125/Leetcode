class Solution {
public:
    long long countSubstrings(string s) {
        long long ans=0;
        int n=s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(10,vector<int>(10,0)));
        for(int i=0;i<n;i++){
            int val=s[i]-'0';
            for(int j=1;j<10;j++){
                for(int k=0;k<j;k++){
                    int newR=(((k*10))+val)%j;
                    dp[i][j][newR]+= (i==0 ? 0:dp[i-1][j][k]);
                }
                dp[i][j][val%j]++;
            }
            ans+=dp[i][val][0];
        }return ans;
    }
};
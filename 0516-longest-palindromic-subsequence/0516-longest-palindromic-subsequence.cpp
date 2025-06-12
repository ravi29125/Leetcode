class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2(text1.rbegin(),text1.rend());
        int n=text1.size(),m=n;
        vector<vector<int>> memo(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    memo[i][j]+=(memo[i-1][j-1]+1);
                }else{
                    memo[i][j]=max(memo[i][j-1],memo[i-1][j]);
                }
            }
        }return memo[n][m];
    }
};
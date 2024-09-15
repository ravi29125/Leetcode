class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        vector<int> memo(m+1,1e9+7);
        memo[0]=0;
        for(int i=1;i<=m;i++){
            for(int j:coins){
                int sub=i-j;
                if(sub<0)continue;
                memo[i]=min(memo[i],memo[sub]+1);
            }
        }return memo[m]==1e9+7?-1:memo[m];
    }
};
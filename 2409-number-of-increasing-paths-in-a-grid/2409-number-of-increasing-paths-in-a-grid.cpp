class Solution {
    int mod=1e9+7;
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int help(vector<vector<int>>& grid,vector<vector<int>> &dp,int n,int m,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int cnt=1;
        for(auto k:dir){
            int x=i+k[0],y=j+k[1];
            if(x<n && x>-1 && y<m && y>-1 && grid[i][j]<grid[x][y]){
                cnt=(cnt+help(grid,dp,n,m,x,y))%mod;
            }
        }return dp[i][j]=cnt;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long res=0;
        vector<vector<int>> arr(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=(res+help(grid,arr,n,m,i,j))%mod;
            }
        }return res;
    }
};
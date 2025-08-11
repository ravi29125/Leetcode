class Solution {
    int dir[5]={0,-1,0,1,0};
    int mod;
    int help(vector<vector<int>>& grid,vector<vector<bool>>& arr,int i,int j,int n,int m){
        int val=grid[i][j]%mod;
        arr[i][j]=true;
        for(int k=1;k<5;k++){
            int x=i+dir[k],y=j+dir[k-1];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]>0 && !arr[x][y]){
                val=(val+help(grid,arr,x,y,n,m))%mod;
            }
        }return val%mod;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        queue<pair<int,int>> q;
        mod=k;
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<bool>> arr(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !arr[i][j]){
                    int val=help(grid,arr,i,j,n,m);
                    if(val==0)ans++;
                }
            }
        }return ans;
    }
};
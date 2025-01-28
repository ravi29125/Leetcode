class Solution {
    int ans;
    vector<vector<int>> arr={{0,1},{1,0},{0,-1},{-1,0}};
    int help(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& mp,int sum){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0)return 0;
        sum+=grid[i][j];
        for(auto k:arr){
            int x=i+k[0],y=j+k[1];
            if(x<grid.size() && x>=0 && y<grid[0].size() && y>=0 && grid[x][y]>0 && !mp[x][y]){
                mp[x][y]=true;
                sum+=help(x,y,grid,mp,0);
            }
        }
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> mp(n,vector<bool>(m,false));
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !mp[i][j]){
                    mp[i][j]=true;
                    ans=max(ans,help(i,j,grid,mp,0));
                }
            }
        }return ans;
    }
};
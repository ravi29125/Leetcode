class Solution {
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    void help(vector<vector<char>>& arr,int i,int j,int n,int m,vector<vector<bool>>& flag){
        for(auto k:dir){
            int x=i+k[0],y=j+k[1];
            if(x>-1 && y>-1 && x<arr.size() && y<arr[0].size() && arr[x][y]=='1' && !flag[x][y]){
                flag[x][y]=true;
                help(arr,x,y,n,m,flag);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        vector<vector<bool>> flag(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !flag[i][j]){
                    cnt++;
                    flag[i][j]=true;
                    help(grid,i,j,n,m,flag);
                }
            }
        }return cnt;
    }
};
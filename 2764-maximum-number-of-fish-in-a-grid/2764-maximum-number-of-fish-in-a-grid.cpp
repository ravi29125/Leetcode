class Solution {
    int ans;
    vector<vector<int>> arr={{0,1},{1,0},{0,-1},{-1,0}};
    int help(int p,int qq,vector<vector<int>>& grid,vector<vector<bool>>& mp){
        int sum=grid[p][qq];
        queue<pair<int,int>> q;
        q.push({p,qq});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto k=q.front();
                q.pop();
                int i=k.first,j=k.second;
                for(auto k:arr){
                    int x=i+k[0],y=j+k[1];
                    if(x<grid.size() && x>=0 && y<grid[0].size() && y>=0 && grid[x][y]>0 && !mp[x][y]){
                        sum+=grid[x][y];
                        mp[x][y]=true;
                        q.push({x,y});
                    }
                }
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
                    //cout<<i<<" "<<j<<" ";
                    mp[i][j]=true;
                    int mx=help(i,j,grid,mp);//mp[i][j]=false;
                    cout<<mx<<endl;
                    ans=max(mx,ans);
                }
            }
        }return ans;
    }
};
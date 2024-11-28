class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>> d={{1,0},{-1,0},{0,1},{0,-1}};
        if(grid[0][0]==0){
            pq.emplace(0,0,0);
        }else{
            pq.emplace(1,0,0);
        }
        int ans=-1;
        vector<vector<int>> mp(n,vector<int>(m,INT_MAX));
        while(!pq.empty()){
            auto [k,i,j]=pq.top();pq.pop();
            for(auto p:d){
                int x=p.first,y=p.second;
                if(i+x>-1 && j+y>-1 && i+x<n && j+y<m && mp[i+x][j+y]>k+grid[i+x][j+y]){
                    mp[i+x][j+y]=k+grid[i+x][j+y];
                    pq.emplace(k+grid[i+x][j+y],i+x,j+y);
                }
            }
            //cout<<i<<" "<<j<<" "<<k<<endl;
        }return mp[n-1][m-1];
    }
};
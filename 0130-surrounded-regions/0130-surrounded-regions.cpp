class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size(),m=b[0].size();
        vector<vector<char>> arr(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(b[i][0]=='O'){
                q.push({i,0});
            }
        }
        for(int i=0;i<n;i++){
            if(b[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(b[0][i]=='O'){
                q.push({0,i});
            }
        }
        for(int i=0;i<m;i++){
            if(b[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
        int dir[]={0,-1,0,1,0};
        while(!q.empty()){
            auto val=q.front();
            arr[val.first][val.second]='O';
            q.pop();
            for(int i=1;i<5;i++){
                int x=val.first+dir[i];
                int y=val.second+dir[i-1];
                if(x<n && y<m && x>-1 && y>-1 && b[x][y]=='O' && arr[x][y]=='X'){
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j]=arr[i][j];
            }
        }
    }
};
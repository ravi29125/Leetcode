class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans=mat;
        int n=mat.size();int m=mat[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    ans[i][j]=-1;
                    cnt++;
                }
            }
        }
        // sort(arr.begin(),arr.end());
        int p=1;
        vector<int> dir={0,-1,0,1,0};
        while(cnt>0){
            while(!q.empty()){
                auto k=q.front();q.pop();
                for(int i=1;i<5;i++){
                    int x=k.first+dir[i],y=k.second+dir[i-1];
                    if(x>=0 && y>=0 && x<n && y<m && ans[x][y]==-1){
                        ans[x][y]=ans[k.first][k.second]+1;
                        q.push({x,y});
                        cnt--;
                    }
                }
            }
            p++;
        }
        return ans;
    }
};
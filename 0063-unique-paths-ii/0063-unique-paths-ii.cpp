class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int v=(g[0][0]==1)?0:1;
        int b=v;
        for(int i=0;i<n;i++)if(b && g[i][0]==0)g[i][0]=1;else g[i][0]=0,b=0;
        b=v;
        for(int i=1;i<m;i++)if(b && g[0][i]==0)g[0][i]=1;else g[0][i]=0,b=0;
        for(auto k:g){
            for(auto l:k)cout<<l<<" ";cout<<endl;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(g[i][j]==1){
                    g[i][j]=0;
                }else{
                    g[i][j]=g[i-1][j]+g[i][j-1];
                }
            }
        }
        return g[n-1][m-1];
    }
};
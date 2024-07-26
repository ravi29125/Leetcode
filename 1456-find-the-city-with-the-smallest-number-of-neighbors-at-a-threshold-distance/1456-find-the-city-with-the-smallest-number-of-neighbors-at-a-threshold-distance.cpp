class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long>> grid(n,vector<long>(n,INT_MAX));
        for(vector<int> k:edges){
            grid[k[0]][k[1]]=k[2];
            grid[k[1]][k[0]]=k[2];
        }
        for(int i=0;i<n;i++) grid[i][i]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(grid[i][k]!=INT_MAX && grid[j][i]!=INT_MAX)
                    grid[j][k]=min(grid[j][i]+grid[i][k],grid[j][k]);
                }
            }
        }
        //for(int i=0;i<n;i++,cout<<endl)for(int j=0;j<n;j++,cout<<" ")cout<<grid[i][j];
        int ans=-1,c=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && grid[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=c){
                ans=i;
                c=cnt;
            }
        }
        return ans;
    }
};
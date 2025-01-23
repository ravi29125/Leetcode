class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> flag(n,vector<bool>(m,false));
        vector<int> arr(m);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++,arr[j]++;
            }
            if(cnt>1){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1)flag[i][j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(arr[i]>1){
                for(int j=0;j<n;j++){
                    if(grid[j][i]==1)flag[j][i]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag[i][j])ans++;
            }
        }return ans;
    }
};
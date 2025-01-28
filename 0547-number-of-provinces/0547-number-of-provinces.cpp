class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==0 && grid[i][k]==1 && grid[k][j]==1){
                        grid[i][j]=1;
                    }
                }
            }
        }
        unordered_set<string> s;
        for(auto k:grid){
            string r="";
            for(int i:k)r+=('0'+i);
            s.insert(r);
        }return s.size();
    }
};
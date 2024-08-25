class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size();
        m=grid[0].size();
        int cn0=0,cn1=0;
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                if(grid[i][j]!=grid[i][k])cn0++;
                j++;
                k--;
            }
        }
        for(int i=0;i<m;i++){
            int j=0,k=n-1;
            while(j<k){
                if(grid[j][i]!=grid[k][i])cn1++;
                j++;
                k--;
            }
        }return min(cn1,cn0);
    }
};
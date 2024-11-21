class Solution {
    void help(int row,int col,vector<vector<char>>&grid){
        for(int i=col+1;i<grid[0].size();i++){
            if(grid[row][i]=='.' || grid[row][i]=='-'){
                grid[row][i]='-';
            }else{
                break;
            }
        }
        for(int i=col-1;i>-1;i--){
            if(grid[row][i]=='.' || grid[row][i]=='-'){
                grid[row][i]='-';
            }else{
                break;
            }
        }
        for(int i=row+1;i<grid.size();i++){
            if(grid[i][col]=='.' || grid[i][col]=='-'){
                grid[i][col]='-';
            }else{
                break;
            }
        }
        for(int i=row-1;i>-1;i--){
            if(grid[i][col]=='.' || grid[i][col]=='-'){
                grid[i][col]='-';
            }else{
                break;
            }
        }
    }
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(n,vector<char>(m,'.'));
        for(auto k:guards){
            grid[k[0]][k[1]]='G';
        }
        for(auto k:walls){
            grid[k[0]][k[1]]='W';
        }
        for(auto k:guards){
            help(k[0],k[1],grid);
        }
        int ans=0;
        for(auto i:grid)for(auto j:i)if(j=='.')ans++;
        return ans;
    }
};
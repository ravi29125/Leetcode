
/*
int n=grid.size(),m=grid[0].size();
        vector<vector<vector<long>>> arr(n,vector<vector<long>>(m,vector<long>(2,INT_MAX)));
        arr[0][0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //grid[i][j][1]
                if(arr[i][j][1]!=INT_MAX){
                    if(grid[i][j]==1){
                        if(j+1<m){
                            arr[i][j+1][1]=min(arr[i][j+1][1],arr[i][j][1]+1);
                        }
                    }else if(grid[i][j]==2){
                        if(j-1>-1){
                            arr[i][j-1][1]=min(arr[i][j-1][1],arr[i][j][1]+1);
                        }
                    }else if(grid[i][j]==3){
                        if(i+1<n){
                            arr[i+1][j][1]=min(arr[i+1][j][1],arr[i][j][1]+1);
                        }
                    }else{
                        if(i-1>-1){
                            arr[i-1][j][1]=min(arr[i-1][j][1],arr[i][j][1]+1);
                        }
                    }
                }
                //grid[i][j][0];
                if(grid[i][j]==1){
                    if(j+1<m){
                        arr[i][j+1][0]=min(arr[i][j+1][0],arr[i][j][0]+1);
                    }
                    if(j-1>-1){
                        arr[i][j-1][1]=min(arr[i][j-1][1],arr[i][j][0]+1);
                    }if(i+1<n){
                        arr[i+1][j][1]=min(arr[i+1][j][1],arr[i][j][0]+1);
                    }if(i-1>-1){
                        arr[i-1][j][1]=min(arr[i-1][j][1],arr[i][j][0]+1);
                    }
                }else if(grid[i][j]==2){
                    if(j-1>-1){
                        arr[i][j-1][0]=min(arr[i][j-1][0],arr[i][j][0]+1);
                    }
                    if(j+1<m){
                        arr[i][j+1][1]=min(arr[i][j+1][1],arr[i][j][0]+1);
                    }if(i+1<n){
                        arr[i+1][j][1]=min(arr[i+1][j][1],arr[i][j][0]+1);
                    }if(i-1>-1){
                        arr[i-1][j][1]=min(arr[i-1][j][1],arr[i][j][0]+1);
                    }
                }else if(grid[i][j]==3){
                    if(i+1<n){
                        arr[i+1][j][0]=min(arr[i+1][j][0],arr[i][j][0]+1);
                    }
                    if(j+1<m){
                        arr[i][j+1][1]=min(arr[i][j+1][1],arr[i][j][0]+1);
                    }if(j-1>-1){
                        arr[i][j-1][1]=min(arr[i][j-1][1],arr[i][j][0]+1);
                    }if(i-1>-1){
                        arr[i-1][j][1]=min(arr[i-1][j][1],arr[i][j][0]+1);
                    }
                }else{
                    if(i-1>-1){
                        arr[i-1][j][0]=min(arr[i-1][j][0],arr[i][j][0]+1);
                    }
                    if(j+1<m){
                        arr[i][j+1][1]=min(arr[i][j+1][1],arr[i][j][0]+1);
                    }if(j-1>-1){
                        arr[i][j-1][1]=min(arr[i][j-1][1],arr[i][j][0]+1);
                    }if(i+1<n){
                        arr[i+1][j][1]=min(arr[i+1][j][1],arr[i][j][0]+1);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j][0]<<" ";
            }cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j][1]<<" ";
            }cout<<endl;
        }
        return min(arr[n-1][m-1][0],arr[n-1][m-1][1]);
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        vector<vector<int>> minChanges(numRows, vector<int>(numCols, INT_MAX));
        minChanges[0][0] = 0;
        while (true) {
            vector<vector<int>> prevState = minChanges;
            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numCols; col++) {
                    if (row > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row - 1][col] +
                                    (grid[row - 1][col] == 3 ? 0 : 1));
                    }
                    if (col > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col - 1] +
                                    (grid[row][col - 1] == 1 ? 0 : 1));
                    }
                }
            }
            for (int row = numRows - 1; row >= 0; row--) {
                for (int col = numCols - 1; col >= 0; col--) {
                    if (row < numRows - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row + 1][col] +
                                    (grid[row + 1][col] == 4 ? 0 : 1));
                    }
                    if (col < numCols - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col + 1] +
                                    (grid[row][col + 1] == 2 ? 0 : 1));
                    }
                }
            }
            if (prevState == minChanges) {
                break;
            }
        }

        return minChanges[numRows - 1][numCols - 1];
    }
};
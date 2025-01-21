class Solution {
    void help(vector<vector<int>>& grid,vector<vector<long long>>& arr,int i,int j){
        if(i-1>-1 && j-1>-1){
            if(arr[i-1][j]>arr[i][j-1]){
                grid[i-1][j]=0;
                help(grid,arr,i-1,j);
            }else{
                grid[i][j-1]=0;
                help(grid,arr,i,j-1);
            }
        }else if(i-1>-1){
            grid[i-1][j]=0;
            help(grid,arr,i-1,j);
        }else if(j-1>-1){
            grid[i][j-1]=0;
            help(grid,arr,i,j-1);
        }
    }
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long min_result = LLONG_MAX;
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long row2_sum = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            row1_sum -= grid[0][i];
            min_result = min(min_result, max(row1_sum, row2_sum));
            row2_sum += grid[1][i];
        }
        return min_result;
    }
};
/*
20 3 20 17 2 12 15 17 4 15 
20 10 13 14 15 5 2 3 14 3 
20 23 43 60 62 74 89 106 110 125 
40 50 63 77 92 97 99 109 124 128 
0 0 0 0 0 0 0 0 0 0 
20 10 13 14 15 5 2 3 14 0 
0 0 0 0 0 0 0 0 0 0 
20 30 43 57 72 77 79 82 96 96 
*/
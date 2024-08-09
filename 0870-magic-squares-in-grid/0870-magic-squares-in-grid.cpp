class Solution {
    bool check(int sr,int sc,vector<vector<int>>& g){
        vector<int> arr(9,0);
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(g[i][j]==0)return false;
                else if(g[i][j]>9)return false;
                if(arr[g[i][j]-1]==1)return false;
                arr[g[i][j]-1]++;
            }
        }return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(check(i-1,j-1,grid)){
                    //cout<<"One"<<endl;
                    int v1=grid[i][j]+grid[i-1][j-1]+grid[i+1][j+1];
                    int v2=grid[i][j]+grid[i-1][j+1]+grid[i+1][j-1];
                    int v3=grid[i][j]+grid[i][j-1]+grid[i][j+1];
                    int v4=grid[i][j]+grid[i][j+1]+grid[i][j-1];
                    int v5=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1];
                    int v6=grid[i][j-1]+grid[i][j]+grid[i][j+1];
                    int v7=grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                    int v8=grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1];
                    int v9=grid[i-1][j]+grid[i][j]+grid[i+1][j];
                    int v0=grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1];
                    if(v1==v2&&v2==v3&&v3==v4&&v4==v5&&v5==v6&&v6==v7&&v7==v8&&v8==v9&&v0==v1)cnt++;
                }
            }
        }return cnt;
    }
};
/*
4 7 8 = 19
9 5 1 = 15
2 3 6 = 11

2 7 6 = 15
1 5 9 = 15
4 3 8 = 15
7 15 23

1  8  6


*/
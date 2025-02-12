class Solution {
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    void help(vector<vector<int>>& arr, int i, int j, int val,vector<vector<bool>>& flag,int curr){
        if(arr[i][j]==curr) arr[i][j]=val;
        else return ;
        for(auto k:dir){
            int x=i+k[0],y=j+k[1];
            if(x>-1 && y>-1 && x<arr.size() && y<arr[0].size() && arr[x][y]==curr && !flag[x][y]){
                flag[x][y]=true;
                help(arr,x,y,val,flag,curr);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();int m=image[0].size();
        vector<vector<bool>> flag(n,vector<bool>(m,false));
        help(image,sr,sc,color,flag,image[sr][sc]);
        return image;
    }
};
/*
int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==0){
                    int sum=0;
                    int mx=0;
                    if(i-1>-1){
                        sum+=ans[i-1][j];
                        mx=max(mx,ans[i-1][j]+1);
                    }
                    if(j-1>-1){
                        sum+=ans[i][j-1];
                        mx=max(mx,ans[i][j-1]+1);
                    }
                    if(i+1<n){
                        sum+=ans[i+1][j];
                        mx=max(mx,ans[i+1][j]+1);
                    }
                    if(j+1<m){
                        sum+=ans[i][j+1];
                        mx=max(mx,ans[i][j+1]+1);
                    }
                    if(mx!=0){
                        ans[i][j]=min(mx,sum);
                    }
                }else{
                    ans[i][j]=0;
                }
            }
        }return ans;
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> res(r , vector<int>(c,-1));
        int dx[4] = {0 , 0 , -1, 1};
        int dy[4] = {-1 , 1 , 0, 0};

        queue<pair<int,int>> q;
         for(int i = 0 ; i<r ; i++){
            for(int j = 0 ; j<c ; j++){
                if(isWater[i][j] == 1){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
         }
        while(!q.empty()){
            auto temp = q.front();
            int R = temp.first;
            int C = temp.second;
            q.pop();
            for(int k = 0 ; k<4 ; k++){
                int x = R + dx[k];
                int y = C + dy[k];
                if((x>=0 and x<r and y>=0 and y<c) && res[x][y] == -1){
                    res[x][y] = res[R][C] + 1;
                    q.push({x,y});
                }
            }
        }return res;
    }
};
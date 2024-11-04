class Solution {
public:
    int minTimeToReach(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> d={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<>> pq;
        pq.push({0,0,0,0});
        while(!pq.empty()){
            auto [cur,i,j,p]=pq.top();
            pq.pop();
            for(auto k:d){
                int x=i+k[0],y=k[1]+j;
                if(x<n && x>-1 && y<m && y>-1){
                    int val=max(arr[x][y]+(p==1?2:1),cur+(p==1?2:1));
                    if(dp[x][y]>val){
                        dp[x][y]=val;
                        if(p==0){
                            pq.push({val,x,y,1});
                        }else{
                            pq.push({val,x,y,0});
                        }
                        if(dp[n-1][m-1]!=INT_MAX)return val;
                    }
                }
            }
        }return dp[n-1][m-1];
    }
};
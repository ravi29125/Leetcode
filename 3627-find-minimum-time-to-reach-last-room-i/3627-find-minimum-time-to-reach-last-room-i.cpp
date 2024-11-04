class Solution {
public:
    int minTimeToReach(vector<vector<int>>& arr) {
        vector<vector<int>> d={{0,1},{1,0},{0,-1},{-1,0}};
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});
        arr[0][0]=0;
        while(!pq.empty()){
            auto [cur,i,j]=pq.top();pq.pop();
            //cout<<k<<" "<<i<<" "<<j<<endl;
            for(auto k:d){
                int x=k[0]+i,y=k[1]+j;
                if(x>-1 && x<n && y>-1 && y<m){
                    int val=max(arr[x][y]+1,cur+1);
                    if(val<dp[x][y]){
                        dp[x][y]=val;
                        pq.push({val,x,y});
                    }
                    //if(dp[n-1][m-1]!=INT_MAX)return val;
                }
            }
        }return dp[n-1][m-1];
    }
};
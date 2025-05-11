class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<int>> arr(n);
        vector<vector<int>> wt(n,vector<int>(n,-1));
        for(auto k:edges){
            wt[k[0]][k[1]]=k[2];
            arr[k[0]].push_back(k[1]);
        }
        int ans=-1;
        vector<set<int>> dp(n);
        for(int i=0;i<n;i++)dp[i].insert(0);
        for(int i=0;i<k;i++){
            vector<set<int>> tt(n);
            for(int j=0;j<n;j++){
                if(dp[j].size()>0){
                    for(auto q:dp[j]){
                        for(auto k:arr[j]){
                            int val=q+wt[j][k];
                            if(val<t)
                            tt[k].insert(val);
                        }
                    }
                }
            }dp=tt;
        }
        for(auto p:dp){
            for(auto op:p){
                ans=max(ans,op);
            }
        }
        return ans;
    }
};
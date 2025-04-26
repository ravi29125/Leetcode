class Solution {
    vector<int> ti,to;
    int t;
    int help(vector<int>& nums,vector<int>& dp,vector<vector<int>>& mp,int curr,int p){
        ti[curr]=t++;
        int val=nums[curr];
        for(auto k:mp[curr]){
            if(k!=p){
                val^=help(nums,dp,mp,k,curr);
            }
        }
        to[curr]=t++;
        return dp[curr]=val;
    }
    bool isA(int u,int v){
        return ti[u]<ti[v] && to[v]<to[u];
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& e) {
        int n=nums.size();
        t=0;
        ti=vector<int>(n,0);
        to=vector<int>(n,0);
        vector<int> arr(n,-1);
        vector<vector<int>> adj(n,vector<int>());
        for(auto k:e){
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        int tot=help(nums,arr,adj,0,-1);
        //tot=0;for(int i:nums)tot^=i;
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p1=arr[i],p2=arr[j],p3=tot;
                if(isA(i,j)){
                    p1=p1^p2;
                }else if(isA(j,i)){
                    p2=p2^p1;
                }
                p3=p3^p2^p1;
                ans=min(ans,(max({p1,p2,p3})-min({p1,p2,p3})));
            }
        }
        return ans;
    }
};
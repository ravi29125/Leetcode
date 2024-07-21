class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> cnt(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(auto k:prerequisites){
            cnt[k[1]]++;
            adj[k[0]].push_back(k[1]);
        }int visi=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(cnt[i]==0)q.push(i);
        }
        while(!q.empty()){
            int val=q.front();q.pop();
            visi++;
            for(auto k:adj[val]){
                cnt[k]--;
                if(cnt[k]==0)q.push(k);
            }
        }
        return visi==n;
    }
};
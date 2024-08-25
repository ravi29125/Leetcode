class Solution {
    int helP(vector<vector<int>>& g){
        queue<int> pq;
        int k=g.size()-1;
        int cnt=0;
        pq.push(0);
        vector<bool> vis(k+1,false);
        while(!pq.empty()){
            int n=pq.size();
            while(n--){
                int val=pq.front();pq.pop();
                //cout<<val<<" ";
                for(int i:g[val]){
                    if(i==k)return cnt+1;
                    if(!vis[i])
                    pq.push(i);
                    vis[i]=true;
                }
            }cnt++;//cout<<endl;
        }
        return cnt;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& qu) {
        vector<vector<int>> g(n);
        for(int i=0;i<n-1;i++){
            g[i].push_back(i+1);
            //g[i+1].push_back(i);
        }
        int k=qu.size();
        vector<int> ans(k);
        int i=0;
        for(auto d:qu){
            int u=d[0],v=d[1];
            g[u].push_back(v);
            ans[i++]=helP(g);
        }return ans;
    }
};
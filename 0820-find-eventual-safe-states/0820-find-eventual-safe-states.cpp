class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        set<int> ans;
        //vector<vector<int>> mp(n,vector<int>(n));
        vector<vector<int>> re(n);
        vector<int> flag(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int j:graph[i])re[j].push_back(i);
            flag[i]=graph[i].size();
            if(flag[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int val=q.front();q.pop();
            ans.insert(val);
            for(int i:re[val]){
                //if(mp[i][val]==1){
                    //mp[i][val]--;
                    flag[i]--;
                    if(flag[i]==0){
                        q.push(i);
                    } 
                //}
            }
        }
        return {ans.begin(),ans.end()};
    }
};
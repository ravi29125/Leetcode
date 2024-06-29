class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        vector<int> deg(n);
        vector<vector<int>> ans(n),v(n);
        vector<set<int>> s(n);
        for(auto k:e){
            deg[k[1]]++;
            v[k[0]].push_back(k[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int fr=q.front();q.pop();
                for(int j:v[fr]){
                    deg[j]--;
                    for(int i:s[fr])s[j].insert(i);
                    s[j].insert(fr);
                    if(deg[j]==0)q.push(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j:s[i])ans[i].push_back(j);
        }return ans;
    }
};
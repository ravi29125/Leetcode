class Solution {
    vector<int> help(int n, vector<vector<int>>& a) {
        unordered_map<int,int> mp;
        set<vector<int>> arr;
        for(auto k:a)arr.insert(k);
        vector<vector<int>> adj(n+1,vector<int>());
        for(auto k:arr){
            adj[k[0]].push_back(k[1]);
            mp[k[1]]++;
        }
        queue<int> q;
        int v=0;
        int h=mp.size();
        for(int k=1;k<=n;k++){
            if(mp[k]==0)q.push(k);
        }
        vector<int> ans;
        //cout<<q.size()<<" ";
        while(!q.empty()){
            int val=q.front();q.pop();
            v++;
            for(auto k:adj[val]){
                mp[k]--;
                if(mp[k]==0)q.push(k);
            }
            ans.push_back(val);
        }
        if(v==n)return ans;
        return {};
    }
public:
    vector<vector<int>> buildMatrix(int k,vector<vector<int>>& r,vector<vector<int>>& c) {
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> row=help(k,r),col=help(k,c);
        //for(int i:row)cout<<i<<" ";cout<<endl;
        //for(int i:col)cout<<i<<" ";cout<<endl;
        if(row.size()==0 || col.size()==0)return {};
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[row[i]]=i;
        }
        for(int i=0;i<k;i++){
            ans[mp[col[i]]][i]=col[i];
        }
        return ans;
    }
};
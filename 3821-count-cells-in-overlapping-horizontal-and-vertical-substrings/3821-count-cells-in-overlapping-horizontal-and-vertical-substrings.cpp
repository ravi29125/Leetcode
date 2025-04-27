class Solution {
    vector<int> help(string s){
        int n=s.size();
        int cnt=0;
        vector<int> arr(n,0);
        for(int i=1;i<n;i++){
            int curr=arr[i-1];
            while(curr>0 && s[i]!=s[curr]){
                curr=arr[curr-1];
            }
            arr[i]=curr+(s[i]==s[curr]?1:0);
        }return arr;
    }
public:
    int countCells(vector<vector<char>>& grid, string pat) {
        int n=grid.size(),m=grid[0].size();
        map<pair<int,int>,int> mp1,mp2;
        vector<pair<int,int>> h,v;
        string r1="",r2="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                r1+=grid[i][j];
                h.push_back({i,j});
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                r2+=grid[i][j];
                v.push_back({i,j});
            }
        }
        vector<int> l1=help(pat+"#"+r1);
        vector<int> l2=help(pat+"#"+r2);
        n=l1.size();
        m=pat.size();
        vector<int> h1(h.size()+1,0),h2(h.size()+1,0);
        for(int i=m;i<n;i++){
            if(l1[i]==m){
                int val=i-(m);
                int o=val-m;
                h1[val]--;
                h1[o]++;
            }
            if(l2[i]==m){
                int val=i-(m);
                int o=val-m;
                h2[val]--;
                h2[o]++;
            }
        }
        if(h1[0]>0){
            mp1[{h[0].first,h[0].second}]++;
        }
        if(h2[0]>0){
            mp2[{v[0].first,v[0].second}]++;
        }
        for(int i=1;i<h1.size();i++){
            h1[i]+=h1[i-1];
            h2[i]+=h2[i-1];
            if(h1[i]>0){
                mp1[{h[i].first,h[i].second}]++;
            }
            if(h2[i]>0){
                mp2[{v[i].first,v[i].second}]++;
            }
        }
        int cnt=0;
        for(auto k:mp1){
            if(mp2.find(k.first)!=mp2.end())cnt++;
        }
        return cnt;
    }
};
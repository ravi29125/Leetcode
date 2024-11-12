class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int mx=0,j=0,n=items.size();
        unordered_map<int,int> mp;
        set<int> s(queries.begin(),queries.end());
        for(int i:s){
            if(mp.find(i)!=mp.end()){
                i=mp[i];
                continue;
            }
            while(j<n && items[j][0]<=i){
                mx=max(mx,items[j][1]);
                j++;
            }
            mp[i]=mx;
        }
        for(int &i:queries){
            i=mp[i];
        }return queries;
    }
};
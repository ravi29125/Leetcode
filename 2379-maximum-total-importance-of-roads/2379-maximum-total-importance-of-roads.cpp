class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> mp;
        for(auto i:roads){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        vector<pair<int,int>> ve;
        for(int i=0;i<n;i++){
            ve.push_back({mp[i],i});
        }sort(ve.begin(),ve.end());
        unordered_map<int,int> m;
        int i=1;
        for(auto k:ve){
            m[k.second]=i++;//cout<<k.second<<" "<<i-1<<endl;
        }
        long long sum=0;
        for(auto k:roads){
            sum+=m[k[0]]+m[k[1]];
        }return sum;
    }
};
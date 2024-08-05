class Solution {
public:
    string kthDistinct(vector<string>& arr, int n) {
        unordered_map<string,int> mp;
        for(auto k:arr)mp[k]++;
        vector<string> ans;
        for(auto k:arr)if(mp[k]==1)ans.push_back(k);
        if(ans.size()<n)return "";
        return ans[n-1];
    }
};
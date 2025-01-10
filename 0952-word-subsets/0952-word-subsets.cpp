class Solution {
    unordered_map<char,int> ref;
    bool help(string s){
        unordered_map<char,int> mp;
        for(auto i:s)mp[i]++;
        for(auto k:ref){
            if(k.second>mp[k.first])return false;
        }return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ref.clear();
        for(auto i:words2){
            unordered_map<char,int> t;
            for(auto j:i)t[j]++;
            for(auto k:t)ref[k.first]=max(ref[k.first],k.second);
        }
        vector<string> ans;
        for(auto i:words1){
            if(help(i)){
                ans.push_back(i);
            }
        }return ans;
    }
};
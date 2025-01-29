class Solution {
    bool help(unordered_map<char,int>& mp,unordered_map<char,int>& p){
        for(auto k:mp){
            if(k.second!=p[k.first]) return false;
        }return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp,pp;
        for(auto k:p){
            mp[k]++;
        }
        int j=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            pp[s[i]]++;
            if(i-j >= p.size()){
                pp[s[j++]]--;
            }
            if(help(mp,pp))ans.push_back(j);
        }
        return ans;
    }
};
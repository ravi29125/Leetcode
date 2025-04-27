class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int> mp;
        int mx=0;
        for(auto k:responses){
            unordered_set<string> st;
            for(auto j:k)st.insert(j);
            for(auto j:st){
                mp[j]++;
                mx=max(mx,mp[j]);
            }
        }
        set<string> st;
        for(auto k:mp){
            if(k.second==mx){
                st.insert(k.first);
            }
        }return *st.begin();
    }
};
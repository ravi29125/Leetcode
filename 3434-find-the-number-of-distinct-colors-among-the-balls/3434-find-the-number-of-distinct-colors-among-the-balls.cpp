class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> mp,cnt;
        set<int> s;
        for(auto &k:queries){
            if(mp.find(k[0])!=mp.end()){
                if(mp[k[0]]==k[1]){
                    cnt[k[1]]--;
                }else{
                    if(cnt[mp[k[0]]]==1){
                        cnt.erase(mp[k[0]]);
                        s.erase(mp[k[0]]);
                    }else{
                        cnt[mp[k[0]]]--;
                    }
                }
            }//else{
                mp[k[0]]=k[1];
                cnt[k[1]]++;
                s.insert(k[1]);
            //}
            ans.push_back(s.size());
        }return ans;
    }
};
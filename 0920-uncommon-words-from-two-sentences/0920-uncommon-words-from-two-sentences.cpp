class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string r="";
        s1+=' ';
        for(char i:s1){
            if(i==' '){
                if(r.size()==0)continue;
                mp[r]++;
                r="";
            }else r+=i;
        }
        r="";
        s2+=' ';
        for(char i:s2){
            if(i==' '){
                if(r.size()==0)continue;
                mp[r]++;
                r="";
            }else r+=i;
        }
        vector<string> ans;
        for(auto k:mp){
            if(k.second==1)ans.push_back(k.first);
        }return ans;
    }
};
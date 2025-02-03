class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n=s.size(),m=words.size(),k=words[0].size();
        int sub=m*k;
        unordered_map<string,int> mp;
        unordered_map<string,int> b;
        for(auto j:words)mp[j]++;
        if(sub>n || m==0 || n==0)return ans;
        for(int i=0;i<=n-sub;i++){
            string r=s.substr(i,sub);
            if(b[r]!=0){
                ans.push_back(i);
                continue;
            }
            unordered_map<string,int> m;
            for(int l=0;l<sub;l+=k){
                m[r.substr(l,k)]++;
            }
            bool f=false;
            for(auto p:words){
                if(mp[p]!=m[p]){f=true;break;}
            }
            if(!f){ans.push_back(i);b[r]++;}
        }return ans;
    }
};
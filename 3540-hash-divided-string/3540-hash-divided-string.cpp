class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i+=k){
            int val=0;
            for(int j=0;j<k;j++){
                val+=s[i+j]-'a';
            }
            val%=26;
            ans+=('a'+val);
        }
        return ans;
    }
};
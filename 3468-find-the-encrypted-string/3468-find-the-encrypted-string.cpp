class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        for(int i=0;i<k;i++){
            s+=s[i];
        }
        int n=s.size();
        for(int i=k;i<n;i++){
            ans+=s[i];
        }return ans;
    }
};
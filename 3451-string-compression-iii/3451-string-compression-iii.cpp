class Solution {
public:
    string compressedString(string s) {
        int i=0,n=s.size();
        int cnt=0;
        string comp="";
        while(i<n){
            char c=s[i];
            cnt=0;
            while(i<n && s[i]==c && cnt<9){
                cnt++;
                i++;
            }
            comp+=to_string(cnt)+c;
        }return comp;
    }
};
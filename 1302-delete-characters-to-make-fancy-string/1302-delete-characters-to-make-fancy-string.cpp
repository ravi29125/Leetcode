class Solution {
public:
    string makeFancyString(string s) {
        string r="";
        int cnt=0;
        int i=0,n=s.size();
        while(i<n){
            cnt=0;
            char ch=s[i];
            while(i<n && s[i]==ch)i++,cnt++;
            cnt=min(cnt,2);
            while(cnt--)r+=ch;
        }return r;
    }
};
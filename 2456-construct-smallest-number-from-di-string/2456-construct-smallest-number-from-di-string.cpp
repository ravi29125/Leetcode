class Solution {
public:
    string smallestNumber(string pattern) {
        string s="",r="";
        char ch='1';
        int n=pattern.size();
        for(int i=0;i<n;i++){
            r+=ch;
            ch++;
            if(pattern[i]=='I'){
                reverse(r.begin(),r.end());
                s+=r;
                r="";
            }
        }
        r+=ch;
        reverse(r.begin(),r.end());
        s+=r;
        return s;
    }
};

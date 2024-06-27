class Solution {
public:
    string reversePrefix(string word, char ch) {
        string r="",s="";
        int cnt=0;
        for(auto i:word){
            if(!cnt){
                r+=i;
                if(i==ch)cnt++;
            }else{
                s+=i;
            }
        }
        if(cnt)
        reverse(r.begin(),r.end());
        return r+s;
    }
};
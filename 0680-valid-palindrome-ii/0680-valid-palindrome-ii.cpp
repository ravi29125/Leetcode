class Solution {
    bool help(string & s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return help(s,i+1,j) || help(s,i,j-1);
            }
            i++;
            j--;
        }return true;
    }
};
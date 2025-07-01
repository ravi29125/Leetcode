class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        int ans=1;
        int n=word.size();
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                cnt++;
            }else{
                ans+=(cnt-1);
                cnt=1;
            }
        }
        ans+=(cnt-1);
        return ans;
    }
};
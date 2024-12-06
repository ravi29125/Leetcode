class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int val=0,n=spaces.size();
        int j=0;
        for(char i:s){
            if(val<n && j==spaces[val]){
                ans+=' ';
                val++;
            }
            //cout<<ans<<" ";
            ans+=i;
            j++;
        }
        return ans;
    }
};
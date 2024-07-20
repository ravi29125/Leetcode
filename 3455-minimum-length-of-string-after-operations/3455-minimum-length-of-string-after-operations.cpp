class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(char i:s)mp[i]++;
        long cnt=0;
        for(auto k:mp){
            //cout<<k.first<<" "<<k.second<<endl;
            cnt+=min(k.second%2==0?2:1,k.second);
        }return cnt;
    }
};
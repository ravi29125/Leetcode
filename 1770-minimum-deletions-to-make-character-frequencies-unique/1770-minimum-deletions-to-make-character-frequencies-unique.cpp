class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> mp;
        for(int i:s)mp[i]++;
        vector<int> cal;
        for(auto k:mp)cal.push_back(k.second);
        int ans=0;
        sort(cal.begin(),cal.end());
        //for(int i:cal)cout<<i<<" ";
        for(int i=cal.size()-2;i>-1;i--){
            if(cal[i]>=cal[i+1]){
                if(cal[i+1]==0){
                    ans+=cal[i];
                    cal[i]=0;
                    continue;
                }
                ans+=cal[i]-(cal[i+1]-1);
                cal[i]-=cal[i]-(cal[i+1]-1);
            }
        }
        return ans;
    }
};
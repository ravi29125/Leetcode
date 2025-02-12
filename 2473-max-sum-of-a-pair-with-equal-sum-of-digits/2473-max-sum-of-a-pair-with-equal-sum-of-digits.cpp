class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        int ans=INT_MIN;
        for(int i:nums){
            int cp=i;
            int val=0;
            while(i>0){
                val+=i%10;
                i/=10;
            }
            mp[val].push(cp);
            if(mp[val].size()>2) mp[val].pop();
        }
        for(auto k:mp){
            int sum=0;
            if(k.second.size()!=2) continue;
            while(k.second.size()>0){
                sum+=k.second.top();
                k.second.pop();
            }
            ans=max(ans,sum);
        }
        return ans==INT_MIN?-1:ans;
    }
};
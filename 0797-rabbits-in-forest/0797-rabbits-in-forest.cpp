class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            if(nums[i]==0)cnt++;
            else
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i:s){
            //if(mp[i]>1 && i<mp[i])
            ans+=((mp[i]+i)/(i+1))*(i+1);
        }
        //cout<<cnt<<" ";
        return ans+cnt;
    }
};
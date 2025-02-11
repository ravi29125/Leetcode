class Solution {
    map<pair<int,long long>,int>mp;
    int help(vector<int>& nums,int target,long long sum,int i){
        if(i==nums.size()){
            if(sum==target) return 1;
            else return 0;
        }
        if(mp.find({i,sum})!=mp.end()) return mp[{i,sum}];
        return mp[{i,sum}]=help(nums,target,sum+nums[i],i+1)+help(nums,target,sum-nums[i],i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums,target,0,0);
    }
};
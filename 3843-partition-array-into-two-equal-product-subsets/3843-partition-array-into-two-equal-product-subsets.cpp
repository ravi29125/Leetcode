class Solution {
    bool rec(vector<int>& nums,int i,int n,long long t1,long long t2){
        if(i==n){
            return t1==t2 && t1==1;
        }
        bool res=false;
        if(t1%nums[i]==0 && rec(nums,i+1,n,t1/nums[i],t2)){
            return true;
        }else if(t2%nums[i]==0 && rec(nums,i+1,n,t1,t2/nums[i])){
            return true;
        }
        return res;
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return rec(nums,0,nums.size(),target,target);
    }
};
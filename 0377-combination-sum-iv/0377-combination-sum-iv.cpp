class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> memo(target+1,0);
        memo[0]=1;
        for(int i=1;i<=target;i++){
            for(int j:nums){
                int sub=i-j;
                if(sub<0)continue;
                memo[i]+=memo[sub];
            }
        }return memo[target];
    }
};
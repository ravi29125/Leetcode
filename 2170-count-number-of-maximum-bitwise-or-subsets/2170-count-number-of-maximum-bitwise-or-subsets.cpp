class Solution {
    int cnt;
    void help(int mx,int i,vector<int>& nums,int curr,int n){
        if(i==n){
            if(curr==mx)cnt++;
            return ;
        }
        help(mx,i+1,nums,curr,n);
        help(mx,i+1,nums,curr|nums[i],n);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int o=0;
        for(int i:nums)o|=i;
        cnt=0;
        help(o,0,nums,0,nums.size());
        return cnt;
    }
};
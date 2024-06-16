class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0,s=nums.size();
        long int mx=1;
        while(mx<=n){
            if(i<s && mx>=nums[i]){
                mx+=nums[i++];
            }else{
                cnt++;
                mx+=mx;
            }
        }return cnt;
    }
};
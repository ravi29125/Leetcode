class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>-1 && nums[i]>=nums[i+1])i--;
        if(i>-1){
            int j=nums.size()-1;
            while(nums[i]>=nums[j])j--;
            int t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
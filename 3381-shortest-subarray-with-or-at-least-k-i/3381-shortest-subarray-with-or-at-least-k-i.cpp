class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),mi=INT_MAX,our;
        for(int i=0;i<n;i++){
            our=nums[i];
            if(our>=k)return 1;
            for(int j=i;j<n;j++){
                our|=nums[j];
                if(our>=k){
                    mi=min(mi,j-i+1);
                }
            }
        }
        if(mi==INT_MAX)return -1;
        return mi;
    }
};
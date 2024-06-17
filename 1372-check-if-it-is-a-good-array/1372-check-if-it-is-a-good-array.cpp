class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd=nums[0];
        for(int i:nums){
            gcd=__gcd(i,gcd);
            if(gcd==1)return 1;
        }return 0;
    }
};
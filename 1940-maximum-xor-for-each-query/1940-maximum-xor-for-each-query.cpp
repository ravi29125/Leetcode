class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int val=0;
        while(maximumBit--){
            val=(val<<1)+1;
        }
        vector<int> ans;
        int cal=0;
        for(int i:nums){
            cal^=i;
            ans.push_back((cal^val));
            //cout<<cal<<" ";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
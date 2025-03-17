class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int,int> m1,m2,m3,m4;
        for(int i:nums4)m4[i]++;
        for(int i:nums1)m1[i]++;
        for(int i:nums2)m2[i]++;
        for(int i:nums3)m3[i]++;
        for(auto i:m1){
            for(auto j:m2){
                for(auto k:m3){
                    int val=i.first+j.first+k.first;
                    ans+=(i.second*j.second*k.second*m4[-val]);
                }
            }
        }
        return ans;
    }
};
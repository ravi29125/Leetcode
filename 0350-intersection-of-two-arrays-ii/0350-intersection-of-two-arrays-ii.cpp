class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp1,mp2;
        for(int i:nums1){
            mp1[i]++;
        }
        for(int j:nums2){
            mp2[j]++;
        }
        for(auto k:mp1){
            int mi=min(k.second,mp2[k.first]);
            for(int j=0;j<mi;j++){
                ans.push_back(k.first);
            }
        }return ans;
    }
};
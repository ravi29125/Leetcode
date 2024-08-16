class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx=arrays[0].back(),mi=arrays[0][0];
        int ans=INT_MIN;
        for(int i=1;i<arrays.size();i++){
            ans=max({mx-arrays[i][0],arrays[i].back()-mi,ans});
            mi=min(mi,arrays[i][0]);
            mx=max(mx,arrays[i].back());
        }return ans;
    }
};
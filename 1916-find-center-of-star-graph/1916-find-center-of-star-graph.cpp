class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int mx=edges[0][0];
        unordered_map<int,int> mp;
        for(auto k:edges){
            for(int i:k){
                mp[i]++;
                if(mp[mx]<mp[i]){
                    mx=i;
                }
            }
        }return mx;
    }
};
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n=potions.size();
        for(int &i:spells){
            long long mi=(success+i-1)/i;
            int it=lower_bound(potions.begin(),potions.end(),mi)-potions.begin();
            ans.push_back(n-it);
        }return ans;
    }
};
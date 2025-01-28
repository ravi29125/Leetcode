class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        for(auto i: map){
            if(i.second%2) return false;
        }return true;
    }
};
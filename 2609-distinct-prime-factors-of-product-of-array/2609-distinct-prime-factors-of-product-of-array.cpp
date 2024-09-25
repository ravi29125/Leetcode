class Solution {
    unordered_map<int,int> mp;
    void help(int num){
        for(int i=2;i<=1001;i++){
            if(num%i==0){
                mp[i]++;
                help(num/i);
                return ;
            }
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        mp.clear();
        for(int i:nums){
            help(i);
        }
        return mp.size();
    }
};
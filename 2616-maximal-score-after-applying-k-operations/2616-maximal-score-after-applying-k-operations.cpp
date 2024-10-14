class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        multiset<double> mul;
        for(int i:nums) mul.insert(i);
        while(k--){
            auto it=mul.rbegin();
            score+=*it;
            int num=ceil((*it)/3);
            //cout<<*it<<" "<<num<<" ";
            mul.erase(mul.find(*it));
            mul.insert(num);
        }return score;
    }
};
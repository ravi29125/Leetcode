class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int &i:nums){
            int val=log10(i)+1;
            if(val%2==0)cnt++;
        }return cnt;
    }
};
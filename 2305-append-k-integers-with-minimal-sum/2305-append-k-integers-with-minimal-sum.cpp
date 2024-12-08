class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum=0;
        sort(nums.begin(),nums.end());
        for(int i:nums)cout<<i<<" ";cout<<endl;
        int j=1;
        for(int i:nums){
            if(i<j)continue;
            if(k<=0){

            }
            else{
                while(k && j<i){
                    sum+=j;
                    //cout<<j<<" ";
                    j++;
                    k--;
                }
                j++;
            }
        }
        while(k--){
            sum+=j;
            j++;
        }
        return sum;
    }
};
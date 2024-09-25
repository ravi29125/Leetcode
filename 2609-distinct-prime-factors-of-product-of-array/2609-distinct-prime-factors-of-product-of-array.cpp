class Solution {
    vector<bool> arr;
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
        arr=vector<bool>(1001,true);
        mp.clear();
        for(int i=2;i*i<=1001;i++){
            for(int j=i*i;j<1001;j+=i){
                arr[j]=false;
            }
        }
        arr[1]=false;
        arr[0]=false;
        for(int i:nums){
            help(i);
        }
        return mp.size();
    }
};
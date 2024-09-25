class Solution {
    vector<bool> arr;
    vector<int> a;
    unordered_map<int,int> mp;
    void help(int num){
        for(int i:a){
            if(num%i==0){
                mp[i]++;
                //cout<<i<<" ";
                while(num>0 && num%i==0){
                    num/=i;
                }
                help(num);
                return ;
            }
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        arr=vector<bool>(1001,true);
        mp.clear();
        a=vector<int>();
        for(int i=2;i*i<=1001;i++){
            for(int j=i*i;j<1001;j+=i){
                arr[j]=false;
            }
        }
        for(int i=2;i<1001;i++){
            if(arr[i])a.push_back(i);
        }
        for(int i:nums){
            help(i);
        }
        return mp.size();
    }
};
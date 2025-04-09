class Solution {
    bool help(int val,vector<int>& nums,vector<bool>& arr,int k,int cur,int st){
        if(k==0) return true;
        if(cur==val) return help(val,nums,arr,k-1,0,0);
        for(int i=st;i<arr.size();i++){
            if(!arr[i] && cur+nums[i]<=val){
                arr[i]=true;
                if(help(val,nums,arr,k,cur+nums[i],i+1)) return true;
                arr[i]=false;
            }
        }return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i:matchsticks){
            sum+=i;
        }
        if(sum%4!=0)return false;
        sum/=4;
        vector<bool> arr(matchsticks.size(),false);
        return help(sum,matchsticks,arr,4,0,0);
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<long,int> mp;
        long long sum=0;
        for(int i:nums)sum+=i;
        long long val=sum-x;
        sum=0;
        int mi=INT_MIN;
        mp[0]=-1;
        cout<<val<<" ";
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-val)!=mp.end()){
                mi=max(mi,i-mp[sum-val]);
                //cout<<mp[sum-val]<<" "<<i<<endl;
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        if(mp.find(sum-val)!=mp.end()){
            mi=max(mi,n-1-mp[sum-val]);
            //cout<<mp[sum-val]<<" "<<i<<endl;
        }
        return mi==INT_MIN?-1:n-mi;
    }
};
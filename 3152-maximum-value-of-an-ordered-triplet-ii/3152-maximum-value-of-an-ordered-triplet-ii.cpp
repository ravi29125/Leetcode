class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n),suff(n);
        pref[0]=nums[0];
        //cout<<9<<" "<<pref[1]<<" ";
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i-1]);
            //cout<<pref[i]<<" ";
        }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>-1;i--){
            suff[i]=max(nums[i],suff[i+1]);
        }
        //for(int i:pref)cout<<i<<" ";cout<<endl;
        //for(int i:suff)cout<<i<<" ";cout<<endl;
        long long ans=0;
        for(int i=1;i<n-1;i++){
            long long a=suff[i+1];
            long long val=(pref[i]-nums[i])*a;
            //cout<<pref[i-1]-nums[i]<<" ";
            ans=max(val,ans);
        }
        return ans;
    }
};
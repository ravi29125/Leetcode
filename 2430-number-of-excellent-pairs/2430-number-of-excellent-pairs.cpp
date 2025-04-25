class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans=0;
        unordered_set<int> s;
        int n=nums.size();
        for(int i:nums)s.insert(i);
        vector<int> arr;
        for(int i:s){
            int val=i;
            int cnt=0;
            while(val>0){
                if(val%2==1)
                cnt++;
                val/=2;
            }
            arr.push_back(cnt);
            ///cout<<i<<" "<<cnt<<endl;
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        int i=0,j=n-1;
        while(i<n && j>-1){
            int val=arr[i]+arr[j];
            //cout<<val<<" ";
            if(val<k){
                i++;
            }else{
                ans+=(n-i);
                j--;
            }
        }return ans;
    }
};
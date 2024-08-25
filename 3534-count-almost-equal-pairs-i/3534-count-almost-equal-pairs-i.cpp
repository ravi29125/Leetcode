class Solution {
    bool is(int n,int m){
        vector<int> mp(10,0);
        int ans=0;
        string a=to_string(n),b=to_string(m);
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        int v1=stoi(a),v2=stoi(b);
        if(v1!=v2)return false;
        //return true;
        while(n>0 && m>0){
            if(n%10!=m%10)ans++;
            n/=10;
            m/=10;
        }
        if(n>0 || m>0)ans++;
        return ans>2?false:true;
    }
public:
    int countPairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(is(nums[i],nums[j]))cnt++;
            }
        }return cnt;
    }
};

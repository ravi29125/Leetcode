class Solution {
public:
    bool help(map<int,int>& n,map<int,int>& m){
        if(n.size()!=m.size())return true;
        for(auto k:n){
            if(k.second!=m[k.first]) return true;
        }return false;
    }    
    bool canSortArray(vector<int>& nums) {
        vector<int> res=nums;
        sort(res.begin(),res.end());
        map<int,int> m1,m2;
        long long cnt=0;
        int n=nums.size();
        vector<int> bits(n,0);
        for(int i=0;i<n;i++){
            long long temp=nums[i];
            cnt=0;
            while(temp!=0){
                if((temp&1)==1)cnt++;
                temp=temp>>1;
            }bits[i]=cnt;
        }m1[nums[0]]++;m2[res[0]]++;
        for(int i=1;i<n;i++){
            if(bits[i]!=bits[i-1] && help(m1,m2)) return false;
            m1[nums[i]]++;m2[res[i]]++;
        }return true;
    }
};
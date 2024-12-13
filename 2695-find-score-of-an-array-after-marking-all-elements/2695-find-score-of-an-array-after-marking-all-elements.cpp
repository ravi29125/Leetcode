class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        multiset<pair<int,int>> mul;
        for(int i=0;i<n;i++){
            mul.insert({nums[i],i});
        }
        while(mul.size()!=0){
            auto it=mul.begin();
            int i=((*it).first),j=((*it).second);
            ans+=i;
            if(j>0 && mul.count({nums[j-1],j-1})){
                mul.erase(mul.find({nums[j-1],j-1}));
                //cout<<1<<endl;
            }
            if(j+1<n  && mul.count({nums[j+1],j+1})){
                mul.erase(mul.find({nums[j+1],j+1}));
                //cout<<2<<endl;
            }
            //cout<<i<<" "<<j<<endl;
            mul.erase(it);
            //cout<<mul.size()<<endl;
        }return ans;
    }
};
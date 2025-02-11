class Solution {
    static unordered_map<int,int> m1,m2;
    bool static cmp1(int a,int b){
        return m1[a]>m1[b];
    }
    bool static cmp2(int a,int b){
        return m2[a]>m2[b];
    }
public:
    int minimumOperations(vector<int>& nums) {
        m1.clear();
        m2.clear();
        //int n1,n2;
        //n1=n2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                m1[nums[i]]++;
                //n1=max(n1,m1[nums[i]]);
            }else{
                m2[nums[i]]++;
                //n2=max(n2,m1[nums[i]]);
            }
        }
        int ans=INT_MAX;
        vector<int> a1,a2;
        for(auto &k:m1){
            a1.push_back(k.first);
        }
        for(auto &p:m2){
            a2.push_back(p.first);
        } 
        sort(a1.begin(),a1.end(),cmp1);
        sort(a2.begin(),a2.end(),cmp2);
        for(int i=0;i<(min((int)a1.size(),2));i++){
            for(int j=0;j<(min((int)a2.size(),2));j++){
                if(a1[i]!=a2[j])ans=min(ans,n-m1[a1[i]]-m2[a2[j]]);
                else ans=min(ans,n-max(m1[a1[i]],m2[a2[j]]));
            }
        }return ans==INT_MAX?0:ans;
    }
};
unordered_map<int,int> Solution::m1,Solution::m2;
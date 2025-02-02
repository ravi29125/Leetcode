class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans=LLONG_MAX,sum=0,cnt=0;
        for(int i:beans){
            sum+=i;
        }
        int n=beans.size();
        sort(beans.begin(),beans.end());
        for(int i=0;i<n;i++){
            if(i>0 && beans[i]==beans[i-1]){

            }else{
                ans=min(ans,cnt+sum-((long long)beans[i]*(n-i)));
            }
            sum-=i;
            cnt+=i;
        }return ans;
    }
};
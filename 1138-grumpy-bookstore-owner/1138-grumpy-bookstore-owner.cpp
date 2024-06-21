class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int sum=0;
        int n=c.size();
        for(int i=0;i<n;i++){
            if(g[i]==0){
                sum+=c[i];
                c[i]=0;
            }
        }
        int i=0,j=0;
        int curr=0;
        while(m--)curr+=c[j++];
        int mx=curr;
        while(j<n){
            curr+=c[j++];
            curr-=c[i++];
            mx=max(mx,curr);
        }
        return sum+mx;
    }
};
class Solution {
    int help(vector<long long> &p1,vector<long long> &p2){
        long mx=0;
        long mi=INT_MAX;
        int n=p1.size();
        for(int i=1;i<n;i++){
            long val=p2[i]-p1[i];
            mx=max(mx,val-mi);
            mi=min(mi,val);
        }return p1[n-1]+mx;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<long long> p1(n+1,0),p2(n+1,0);
        for(int i=0;i<n;i++){
            p1[i+1]=p1[i]+nums1[i];
        }
        for(int i=0;i<n;i++){
            p2[i+1]=p2[i]+nums2[i];
        }
        return max(help(p1,p2),help(p2,p1));
    }
};
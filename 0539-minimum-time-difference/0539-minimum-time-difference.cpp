class Solution {
    int find(string s1,string s2){
        int h1=stoi(s1.substr(0,2)),h2=stoi(s2.substr(0,2));
        int m1=stoi(s1.substr(3,2)),m2=stoi(s2.substr(3,2));
        int val=(h2-h1)*60+(m2-m1);
        //cout<<val<<" ";
        return val;
    }
public:
    int findMinDifference(vector<string>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,find(nums[i],nums[i+1]));
        }
        ans=min(ans,find(nums[n-1],"24:00")+find("00:00",nums[0]));
        return ans;
    }
};
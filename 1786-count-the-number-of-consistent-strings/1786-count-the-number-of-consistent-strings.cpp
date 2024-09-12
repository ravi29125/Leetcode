class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& nums) {
        vector<int> arr(26,0);
        for(char c:allowed){
            arr[c-'a']++;
        }
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool f=true;
            for(char k:nums[i]){
                if(arr[k-'a']==0){
                    f=false;
                    break;
                }
            }if(f)cnt++;
        }return cnt;
    }
};
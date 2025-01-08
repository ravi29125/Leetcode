class Solution {
bool ishelp(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    string p = s2.substr(0, s1.size());
    int startPos = s2.size()-s1.size();
    string q = s2.substr(startPos, s1.size());
    //cout<<p<<" "<<q<<" "<<s1<<endl;
    return (p == q) && (p == s1);
}

public:
    int countPrefixSuffixPairs(vector<string>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ishelp(nums[i],nums[j])){
                    //cout<<nums[i]<<" "<<nums[j]<<endl;
                    cnt++;
                }
            }
        }return cnt;
    }
};
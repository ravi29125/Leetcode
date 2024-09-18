class Solution {
public:
    static bool help(int n1,int n2){
        return to_string(n1)+to_string(n2) > to_string(n2)+to_string(n1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),help);
        string res="";
        for(auto i:nums)res+=to_string(i);
        if(res[0]=='0' && res.size()>1)return "0";
        return res;
    }
};
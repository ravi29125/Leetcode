class Solution {
public:
    int countPalindromicSubsequence(string str) {
        vector<vector<int>> hash(26);
        int n=str.size();
        int ans=0;
        for(int i=0;i<n;i++){
            hash[str[i]-'a'].push_back(i);
        }
        for(auto arr:hash){
            n=arr.size();
            if(n==0 || n==1)continue;
            unordered_set<char> s;
            for(int i=arr[0]+1;i<arr[n-1];i++){
                s.insert(str[i]);
            }
            //cout<<s.size()<<" ";
            ans+=s.size();
        }return ans;
    }
};
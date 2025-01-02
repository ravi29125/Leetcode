class Solution {
    bool h(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int help(string s){
        return h(s[0])&&h(s[s.size()-1]);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+help(words[i]);
        }
        int m=queries.size();
        vector<int> arr(m);
        for(int i=0;i<m;i++){
            arr[i]=pre[queries[i][1]+1]-pre[queries[i][0]];
        }return arr;
    }
};
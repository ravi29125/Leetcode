class Solution {
    vector<int> p;
    int n;
    string s;
    unordered_map<int,vector<int>> mp;
    vector<int> ans;
    void help(int curr,vector<int>& arr){
        if(arr[s[curr]-'a']!=-1){
            p[curr]=arr[s[curr]-'a'];
        }
        int val=arr[s[curr]-'a'];
        arr[s[curr]-'a']=curr;
        for(int i:mp[curr]){
            help(i,arr);
        }
        arr[s[curr]-'a']=val;
    }
    int ansR(int curr){
        int cur=1;
        for(int i:mp[curr]){
            ans[i]=ansR(i);
            cur+=ans[i];
        }
        return ans[curr]=cur;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        p=parent;
        n=s.size();
        this->s=s;
        mp.clear();
        ans=vector<int>(n,0);
        for(int i=0;i<n;i++){
            mp[p[i]].push_back(i);
        }
        vector<int> arr(26,-1);
        help(0,arr);
        mp.clear();
        for(int i=0;i<n;i++){
            mp[p[i]].push_back(i);
            //cout<<p[i]<<" "<<i<<endl;
        }
        ansR(0);
        return ans;
    }
};
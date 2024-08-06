class Solution {
private:
    static map<char,int> m;
public:
    static bool cmp(char a,char b){
        return m[a]>m[b];
    }
    int minimumPushes(string word) {
        int n=word.size();
        m.clear();
        for(auto k:word)m[k]++;
        sort(word.begin(),word.end(),cmp);
        //cout<<word<<endl;
        int a=8;
        vector<int> mp(26,0);
        int ans=0,cnt=0;
        for(auto i:word){
            int j=i-'a';
            if(mp[j]!=0)ans+=mp[j];
            else{
                cnt++;
                if(cnt%a==0) mp[j]=cnt/a;
                else mp[j]=cnt/a+1;
                ans+=mp[j];
            }//cout<<mp[j]<<" ";
        }//for(auto k:mp)cout<<k<<" ";
        return ans;
    }
};
map<char, int> Solution::m;
class Solution {
    struct cmp{
        bool operator()(pair<char,int>& p,pair<char,int> & q){
            if(p.first==q.first)return p.second<q.second;
            return p.first>q.first;
        }
    };
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> q;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!pq.empty())pq.pop();
            }else pq.push({s[i],i});
        }
        while(!pq.empty()){
            q.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        string r="";
        while(!q.empty()){
            //cout<<q.top().first<<" "<<q.top().second<<endl;
            r+=q.top().second;
            q.pop();
        }
        return r;
    }
};
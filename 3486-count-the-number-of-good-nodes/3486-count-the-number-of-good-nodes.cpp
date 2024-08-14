class Tree{
    public:
    int val;
    vector<Tree*> ch;
    Tree(int val){
        this->val=val;
        ch=vector<Tree*>();
    }
};
class Solution {
    int help(Tree *root,int &cnt){
        if(root==nullptr)return 1;
        unordered_set<int> s;
        int val=0;
        int tol=0;
        for(auto i:root->ch){
            //if(i==root)cntinue;
            auto it=find(i->ch.begin(),i->ch.end(),root);
            if(it!=i->ch.end())i->ch.erase(it);
            val=help(i,cnt);
            tol+=val;
            //cout<<val<<" "<<root->val<<" "<<i->val<<endl;
            s.insert(val);
        }
        if(s.size()<=1){
            cnt++;
        }return tol+1;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int,Tree*> mp;
        int mx=0;
        //mp[0]=new Tree(0);
        for(auto k:edges){
            //int mi=min(k[0],k[1]),mx=max(k[0],k[1]);
            //k[0]=mi;k[1]=mx;
            if(mp[k[0]]==0){
                mp[k[0]]=new Tree(k[0]);
            }
            if(mp[k[1]]==0){
                mp[k[1]]=new Tree(k[1]);
            }
            mp[k[0]]->ch.push_back(mp[k[1]]);
            mp[k[1]]->ch.push_back(mp[k[0]]);
            mx=max({mx,k[0],k[1]});
        }
        mx++;
        int cnt=0;
        cout<<help(mp[0],cnt)<<endl;
        return cnt;
    }
};
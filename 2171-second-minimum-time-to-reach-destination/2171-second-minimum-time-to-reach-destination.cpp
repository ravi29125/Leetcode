class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n),h(n);
        for(auto k:edges){
            g[k[0]-1].push_back(k[1]-1);
            g[k[1]-1].push_back(k[0]-1);
        }
        queue<int> q;
        q.push(0);
        //q.push(0);q.push(0);
        int ans=0,res=-1;
        //int c=0;
        while(!q.empty()){
            int m=q.size();
            //c++;
            while(m--){
                int val=q.front();q.pop();
                if(val==n-1){
                    if(res==-1){
                        res=ans;
                    }else return ans;
                }
                for(int i:g[val]){
                    int y=h[i].size();
                    if(y==0 || (y==1 && h[i][0]<ans)){
                        h[i].push_back(ans);
                        q.push(i);
                    }
                }
            }
            if((ans/change)%2==1){
                ans+=change-(ans%change);
            }
            ans+=time;
        }
        //cout<<c;
        return ans;
    }
};
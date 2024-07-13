class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        stack<int> st;
        unordered_map<int,int> rl;
        map<int,int> lth;
        int n=p.size();
        for(int i=0;i<n;i++){
            lth[p[i]]=h[i];
            if(d[i]=='R'){
                rl[p[i]]=0;
            }else{
                rl[p[i]]=1;
            }
        }
        bool f=true;
        for(auto k:lth){
            //cout<<k.first<<" ";
            if(f && (rl[k.first]==1)){
                st.push(k.first);continue;
            }else if(st.empty()){
                st.push(k.first);
                f=false;
            }else if(rl[st.top()]==0 && rl[k.first]==1){
                //cout<<st.size()<<" ";
                bool u=true;
                while(!st.empty() && rl[st.top()]==0 && rl[k.first]==1){
                    int m=lth[st.top()],n=lth[k.first];
                    if(m==n){
                        u=false;
                        st.pop();
                        break;
                    }else if(m<n){
                        //cout<<m<<" "<<n<<endl;
                        lth[k.first]-=1;
                        st.pop();
                    }else{
                        //cout<<k.first<<" "<<st.top();
                        lth[st.top()]-=1;
                        u=false;
                        break;
                    }
                }
                if(u && lth[k.first]>0){
                    st.push(k.first);
                }//cout<<st.size()<<" ";
            }else{
                st.push(k.first);
                //cout<<st.size()<<" ";
                //cout<<st.top()<<endl;
            }
            f=false;
        }
        while(!st.empty()){
            rl[st.top()]=-7;
            st.pop();
        }
        vector<int> ans;
        for(int i:p){
            if(rl[i]==-7)ans.push_back(lth[i]);
        }return ans;
    }
};
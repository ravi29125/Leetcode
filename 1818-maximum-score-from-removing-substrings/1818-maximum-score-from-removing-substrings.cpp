class Solution {
    int help(int x,string p,string &s){
        stack<char> st;
        int ans=0;
        for(char i:s){
            if(st.size()==0){
                st.push(i);
            }else if(i==p[0] && p[1]==st.top()){
                st.pop();
                ans+=x;
                //cout<<i<<endl;
            }else{
                st.push(i);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        string p2="ab",p1="ba";
        if(x<y) swap(x,y),swap(p1,p2);
        return help(x,p1,s)+help(y,p2,s);
    }
};
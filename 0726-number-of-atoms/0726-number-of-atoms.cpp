class Solution {
    string help(string s,int num){
        s+='A';
        string cnt="";
        string curr="";
        map<string,int> mp;
        for(char i:s){
            if(i<='Z' && i>='A'){
                if(cnt.size()==0){
                    cnt+='1';
                }
                if(curr.size()>0)
                mp[curr]+=stoi(cnt);
                //cout<<cnt<<" ";
                cnt="";
                curr="";
                curr+=i;
            }else if(i<='z' && i>='a'){
                curr+=i;
            }else{
                cnt+=i;
            }//cout<<curr<<" "<<cnt<<endl;
        }
        string ans="";
        for(auto k:mp){
            ans+=k.first;
            int val=num*k.second;
            if(val>1)
            ans+=to_string(val);
        }return ans;
    }
public:
    string countOfAtoms(string s) {
        int n=s.size();
        stack<int> st;
        string ans="";
        int j=0;
        while(j<n && s[j]!='('){
            ans+=s[j++];
        }
        //cout<<j<<endl;
        for(int i=j;i<n;i++){
            if(s[i]==')'){
                j=i+1;
                string cnt="";
                while(j<n && s[j]<='9' && s[j]>='0')cnt+=s[j++];
                //cout<<j<<endl;
                if(cnt.size()==0)cnt+='1';
                int val=stoi(cnt);
                cnt="";
                while(!st.empty() && st.top()!='('){
                    cnt+=st.top();st.pop();
                }st.pop();
                reverse(cnt.begin(),cnt.end());
                cnt=help(cnt,val);
                for(char g:cnt){
                    st.push(g);
                }
                i=j-1;
            }else{
                st.push(s[i]);
            }
        }
        string temp="";
        while(!st.empty())temp+=st.top(),st.pop();
        reverse(temp.begin(),temp.end());
        //cout<<temp;
        return help(ans+temp,1);
    }
};
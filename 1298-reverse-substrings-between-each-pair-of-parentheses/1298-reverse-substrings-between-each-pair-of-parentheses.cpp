class Solution {
public:
    string reverseParentheses(string p) {
        stack<char> s;
        string ans="";
        for(char i:p){
            if(i==')'){
                string r="";
                while(s.top()!='('){
                    r+=s.top();
                    s.pop();
                }s.pop();
                if(s.empty())ans+=r;
                else
                for(char j:r)s.push(j);
            }else{
                s.push(i);
            }
        }
        string r="";
        while(!s.empty()){
            r+=s.top();s.pop();
        }
        reverse(r.begin(),r.end());
        return ans+r;

    }
};
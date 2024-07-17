class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        for(int i:asteroids){
            if(s.size()==0){
                s.push(i);
            }else if(i==s.top()||(i>0&&s.top()>0)||(i<0&&s.top()<0)||(s.top()<0&&i>0)){
                s.push(i);
                //cout<<i<<" ";
            }else{
                //cout<<i<<" ";
                while(!s.empty()){
                    if(i==s.top()){s.push(i);break;}
                    else if(abs(i)==abs(s.top())){
                        i=0;
                        s.pop();break;
                    }else if((i>0 && s.top()>0)||(i<0 && s.top()<0)){
                        s.push(i);
                        break;
                    }else{
                        //cout<<i<<" ";
                        if(abs(i)>abs(s.top()))s.pop();
                        else break;
                    }
                }
                if(i && s.empty())s.push(i);
            }
            //cout<<s.size()<<" ";
        }
        while(!s.empty()){
            ans.push_back(s.top());s.pop();
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
    bool isequal(string i,string j){
        if(i.size()!=j.size())return false;
        for(int k=0;k<i.size();k++)if(i[k]!=j[k])return false;
        return true;
    }
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(string i:logs){
            if(isequal(i,"./"))continue;
            if(isequal(i,"../") && !s.empty())s.pop();
            else if(!isequal(i,"../"))s.push(i);
        }
        return s.size();
    }
};
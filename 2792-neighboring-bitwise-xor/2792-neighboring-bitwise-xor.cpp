class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val=0;
        for(int i:derived)val^=i;
        return val==0;
    }
};
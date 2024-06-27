class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> h(26,0);
        for(auto i:word1)h[i-'a']++;
        for(auto i:word2)h[i-'a']--;
        for(int i:h)if(abs(i)>3)return false;
        return true;
    }
};
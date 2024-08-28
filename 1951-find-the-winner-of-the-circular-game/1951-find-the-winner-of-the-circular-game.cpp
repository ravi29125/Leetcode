class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a;
        for(int i=0;i<n;i++)a.push_back(i+1);
        int id=0;
        for(int i=0;i<n-1;i++){
            id=(id+k-1)%a.size();
            a.erase(a.begin()+id);
        }return a[0];
    }
};
class Solution {
    bool help(int op,vector<int>& t, vector<int>& w,int p,int s){
        multiset<int> workers(w.end() - op, w.end());
        for (int i = op - 1; i >= 0; --i) {
            auto it = workers.lower_bound(t[i]);
            if (it != workers.end()) {
                workers.erase(it);
            } else {
                if (p == 0) return false;
                it = workers.lower_bound(t[i] - s);
                if (it == workers.end()) return false;
                workers.erase(it);
                p--;
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size(),m=workers.size();
        int i=1,j=min(n,m);
        int ans=0;
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        while(i<=j){
            int mid=i+(j-i)/2;
            if(help(mid,tasks,workers,pills,strength)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }return ans;
    }
};
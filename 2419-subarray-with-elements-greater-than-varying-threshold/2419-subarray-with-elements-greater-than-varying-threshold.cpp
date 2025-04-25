class DSU{
    vector<int> par,size;
public:
    int mx;
    DSU(int n){
        par=vector<int>(n,0);
        size=vector<int>(n,1);
        for(int i=0;i<n;i++)par[i]=i;
        mx=-1;
    }
    int leader(int num){
        if(num==par[num])return num;
        return par[num]=leader(par[num]);
    }
    void merge(int x,int y){
        int lx=leader(x),ly=leader(y);
        if(lx==ly) return ;
        if(size[lx]>size[ly]){
            size[lx]+=size[ly];
            mx=max(mx,size[lx]);
            par[ly]=lx;
        }else{
            size[ly]+=size[lx];
            mx=max(mx,size[ly]);
            par[lx]=ly;
        }
    }
};
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int th) {
        int n=nums.size();
        if(n==1){
            return th<nums[0]?1:-1;
        }
        DSU dsu(n);
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.rbegin(),arr.rend());
        int j=0;
        for(int i=0;i<n;i++){
            int K=i+1;
            double val=th/K;
            while(j<n && arr[j][0]>val){
                if(arr[j][1]>0 && nums[arr[j][1]-1]==-1){
                    dsu.merge(arr[j][1]-1,arr[j][1]);
                }
                if(arr[j][1]<n-1 && nums[arr[j][1]+1]==-1){
                    dsu.merge(arr[j][1]+1,arr[j][1]);
                }
                nums[arr[j][1]]=-1;
                j++;
            }
            if(dsu.mx>=K) return K;
        }return -1;
    }
};
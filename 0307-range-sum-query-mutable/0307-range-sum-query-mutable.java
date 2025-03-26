class NumArray {

    public int[] arr;
    public int n;

    public void built(int[] nums,int st,int i,int j){
        if(i>j){
            return ;
        }
        if(i==j){
            arr[st]=nums[i];
            return ;
        }
        int mid=i+(j-i)/2;
        built(nums,st*2,i,mid);
        built(nums,st*2+1,mid+1,j);
        arr[st]=arr[st*2]+arr[st*2+1];
    }

    public NumArray(int[] nums) {
        this.n=nums.length;
        this.arr=new int[4*n+1];
        for(int i=0;i<4*n+1;i++)this.arr[i]=0;
        built(nums,1,0,n-1);
    }

    public void up(int i,int s,int val,int l,int h){
        if(l>i || h<i)return ;
        if(l==i && h==i){
            arr[s]=val;
            return ;
        }
        int mid=l+(h-l)/2;
        up(i,s*2,val,l,mid);
        up(i,s*2+1,val,mid+1,h);
        arr[s]=arr[s*2]+arr[s*2+1];
    }
    
    public void update(int index, int val) {
        up(index,1,val,0,n-1);
    }

    public int query(int l,int h,int s,int st,int en){
        if(st>h || l>en) return 0;
        if(l>=st && h<=en) return arr[s];
        int mid=l+(h-l)/2;
        return query(l,mid,s*2,st,en)+query(mid+1,h,s*2+1,st,en);
    }
    
    public int sumRange(int left, int right) {
        return query(0,n-1,1,left,right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
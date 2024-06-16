class Solution {
public:
    static bool comp1(int n1,int n2){
        return to_string(n1) < to_string(n2);
    }
    static bool comp2(int n1,int n2){
        return to_string(n2) < to_string(n1);
    }
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        int flag=0;string res="",zero="";
        if(num<0)flag=1;
        num=abs(num);vector<int> nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }if(flag==0){
            sort(nums.begin(),nums.end(),comp1);
        }else{
            sort(nums.begin(),nums.end(),comp2);
        }for(int i : nums){
            if(i==0 && flag==0) zero+=to_string(i);
            else res+=to_string(i);
            if(res.size()==1 && flag==0) res+=zero;
        }num=stoll(res);
        if(flag==1)return num*-1;
        return num;
    }
};
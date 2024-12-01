bool checkIfExist(int* nums, int numsSize){
   int i,j;
   for(i=0;i<numsSize;i++){
       for(j=0;j<numsSize;j++){
           if(i!=j && nums[i] == 2*nums[j])
           return true;
       }
   }return false;
}
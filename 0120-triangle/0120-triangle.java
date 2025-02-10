class Solution {
    public int minsum = Integer.MAX_VALUE;
    public int minimumTotal(List<List<Integer>> arr) {
        return getAllcom(arr,0,0);     
    }
    Map<List<Integer> , Integer> list = new HashMap<>();
    public int getAllcom(List<List<Integer>> arr,int row,int col){
        if(row == arr.size()){
            return 0;
        }
        if(list.containsKey(Arrays.asList(row,col))){
            return list.get(Arrays.asList(row,col));
        }
        int left  = getAllcom(arr,row + 1,col);
        int right = getAllcom(arr,row + 1,col + 1);
        list.put(Arrays.asList(row,col) , Math.min(left , right ) + arr.get(row).get(col));
        return Math.min(left , right ) + arr.get(row).get(col);
    }
}
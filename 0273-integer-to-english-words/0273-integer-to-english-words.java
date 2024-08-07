class Solution {
    private final String[] one = new String[] {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    private final String[] two = new String[] {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private final String[] three = new String[] {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    public String numberToWords(int num) {
        if(num==0) return "Zero";
        return Help(num);
    }

    private String Help(int num){
        String result=new String();
        if(num<10) result=one[num];
        else if(num<20) result=two[num-10];
        else if(num<100) result= three[num/10] + " " + Help(num%10);
        else if(num<1000) result=Help(num/100)+" Hundred " +Help(num%100);
        else if(num<1000000) result=Help(num/1000)+" Thousand "+Help(num%1000);
        else if(num<1000000000)result=Help(num/1000000)+" Million "+Help(num%1000000);       else result=Help(num/1000000000)+" Billion " +Help(num%1000000000);
        return result.trim();
    }
}
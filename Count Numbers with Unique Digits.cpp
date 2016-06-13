class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if (n==1)return 10;
        int tmp=9;
        int i=1;
        int tmp1=n;
        while(n>1&&tmp>0){
            tmp*=(10-i);
            i++;
            n--;
        }
       
        return countNumbersWithUniqueDigits(tmp1-1)+tmp;
    }
};
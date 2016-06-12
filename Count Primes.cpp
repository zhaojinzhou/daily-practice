class Solution {
public:
    int countPrimes(int n) {
       if(n==0||n==1||n==2)return 0;
       
       vector<bool> tmp(n,0);
       int i=2;
       int nums=0;
       while(i<n){
           if(tmp[i]==0){
           for(int j=i;j<n;j+=i)
           tmp[j]=1;
            nums++;   
           }
           i++;
       }
       return nums;
    }
};
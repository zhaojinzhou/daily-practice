class Solution {
public:
    bool isPalindrome(int x) {
        int tmp;
        int i=1;
        if(x<0)return false; 
        if(x>(INT_MAX/10))
        tmp=1000000000;
        else{
            while(i<=x){
            tmp=i;
            i*=10;
            }    
        }
        
        cout<<tmp;
        i=1;
        while(i<tmp){
            if(((x/i)%10)!=((x/tmp)%10))return false;
            tmp/=10;
            i*=10;
        }
        
        
        
        return true;
    }
};
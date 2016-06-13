class Solution {
public:
    string next(string str, int n){
        if(n==1){
         return   str; 
        }
        
        int count;
        int tmp=0;
        string str1;
        int i=0;
        int size=str.size();
        stringstream ssm;
        
        
        while(i<size){
            count=0;
            tmp=i;
            while(str[i]==str[i+1]){
                i++;
                count++;
            }
                count++;
                str.erase(tmp,count-1);
                ssm.clear();
                ssm<<count;
                ssm>>str1;
                str.insert(tmp,str1);
                size=str.size();
                tmp+=2;
                i=tmp;    
           
            
            
        }
        
        
        return next(str,n-1);
        
    } 
    string countAndSay(int n) {
        
        string str="1";
        str=next(str,n);
        
        return str;
        
    }
};
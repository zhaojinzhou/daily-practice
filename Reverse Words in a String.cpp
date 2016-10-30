class Solution {
public:
    void reverseWords(string &s) {
        char* a[s.size()];
        char *c=new char[s.size()+1];
        strcpy(c,s.data());
        char *p;
        const char* sp=" ";
        p=strtok(c,sp);
        int i=0;
        while(p){
            a[i++]=p;
            
            p=strtok(NULL,sp);
        }
        
        
        string res="";
        for(int j=i-1;j>=0;j--){
            res+=a[j];
            if(j!=0)
            res+=" ";
        }
        
        s= res;
        
    }
};
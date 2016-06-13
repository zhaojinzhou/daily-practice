class Solution {
public:
    string convert(string s, int numRows) {
         string s1[numRows];
         int i=0;
         
         int row=0;
         int flag=0;
         int numRows1=numRows;
         if(numRows==1)return s;
        while(i<s.size()){
                
                while(i<s.size()&&row<numRows1)
             {
                 s1[row]=s1[row]+s[i];
                 i++;
                 row++;
             }   
            
                row--;
            while(i<s.size()&&row>0)
             {
                 row--;
                 s1[row]=s1[row]+s[i];
                 i++;
                 
             }   
             row++;
         
        } 
        
        string s2;
        for(int i=0;i<numRows;i++)
         {
             cout<<s1[i]<<endl;
             s2+=s1[i];
        
         }
        return s2;
    }
};
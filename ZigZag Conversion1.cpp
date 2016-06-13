class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string s1[numRows];
        int j=0;
        while(j<s.size())
        {
            for(int i=0;i<numRows&&j<s.size();i++,j++){
                s1[i]+=s[j];
                
            }
            for(int i=numRows-2;i>0&&j<s.size();i--,j++){
                s1[i]+=s[j];
            }
        }
        string s2;
        for(int i=0;i<numRows;i++){
            s2+=s1[i];
        }
        
        
        return s2;
    }
};
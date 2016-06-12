class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> tmp;
        map<char,int> tmp1;
        int tmp2,tmp3;
        string a="`";
        s.insert(0,a);
        t.insert(0,a);
        for (int i=0;i<s.size();i++){
            
            if(tmp[s[i]]!=tmp1[t[i]])return false;
            tmp[s[i]]=i;
            tmp1[t[i]]=i;
            
            
            
        }
        return true;
        
    }
};
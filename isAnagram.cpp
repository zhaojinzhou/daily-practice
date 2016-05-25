class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int i=0;
        //int num[s.size()];
        while(i<t.size())
        {
            if (s.find(t[i])==-1) return false;
            else s[s.find(t[i])]='0';
            i++;
        }
        return true;
        
    }
};
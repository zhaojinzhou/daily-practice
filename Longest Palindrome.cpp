class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int > mmm;
        for(int i=0;i<s.size();i++)
        mmm[s[i]]++;
        int sum=0;
        bool flag=0;
        for(auto i=mmm.begin();i!=mmm.end();i++){
            if((*i).second%2==0)
            sum+=(*i).second;
            if((*i).second%2==1)
            {   
                
                sum+=(*i).second-1;
                if(!flag){
                    
                    flag=1;
                    sum+=1;
                }
                
            }
        }
        
        return sum;
    }
};
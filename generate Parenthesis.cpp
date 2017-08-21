class Solution {
public:
    bool istrue(string s){
        stack<char> sta;
        for(int i=0 ;i<s.size();i++){
            
            if(s[i]=='('){
                sta.push(s[i]);
            }
            else{
                if(sta.size()==0) return 0;
                sta.pop();
            }
        }
        return true;
    }
    
    
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        for(int i =0 ;i<n; i++){
            s+="(";
        }  
        for(int i =0 ;i<n; i++){
            s+=")";
        }
        if(istrue(s)){
            res.push_back(s);
        }
        
        
        //利用全排列
        while(next_permutation(s.begin(),s.end())){

            if(istrue(s)){
                res.push_back(s);
            }   
        }
        return res;
        
    }
    
    
    
};

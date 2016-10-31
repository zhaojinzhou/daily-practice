class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n,0);
        vector<vector<int>> res(n,tmp);
        
        int start =0,end=n-1;
        int num=1;
        while(start<end){
            for(int i=start;i<end;i++)
            res[start][i]=num++;
            for(int i=start;i<end;i++)
            res[i][end]=num++;
            for(int i=end;i>start;i--)
            res[end][i]=num++;
            for(int i=end;i>start;i--)
            res[i][start]=num++;
            
            start++;
            end--;
            
            
            
        }
        
        if(start==end){
            res[start][end]=num;
        }
        
        return res;
    }
};
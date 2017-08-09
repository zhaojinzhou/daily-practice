class Solution {
public:
    vector<int> row;
    vector<int> column;
    vector<int> diagonal;
    vector<int> antidiagonal;
    int res;
    
    int totalNQueens(int n) {
        row.assign(n,0);
        column.assign(n,0);
        diagonal.assign(2*n,0);
        antidiagonal.assign(2*n,0);
        
        nqueen(0,n-1);
        
        return res;
    }
    
   void nqueen(int left, int right){
       
       if(left>right){
           res++;
       }
       for(int i=0;i<=right;i++){
            if(!(column[i] ==0&&diagonal[left+i]==0&&antidiagonal[right+1+left-i]==0))continue;
            row[left]=i;
            column[i] =diagonal[left+i]=antidiagonal[right+1+left-i]=1;

            nqueen(left+1,right);
            column[i] =diagonal[left+i]=antidiagonal[right+1+left-i]=0;
            row[left]=0;
       }
       
   }
};

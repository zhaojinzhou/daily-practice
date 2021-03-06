class Solution {
public:

	vector<int> row;
	vector<int> column;
	vector<int> diagonal;
	vector<int> antidiagonal;


	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;   
		column.assign(n,0);
		diagonal.assign(2*n,0);
		antidiagonal.assign(2*n,0);
		row.assign(n,0);


		solveNqueens(res, 0, n-1);

		return res;

	}
  
  //------类似全排列
	void solveNqueens(vector<vector<string>>& res, int left, int right){

		if(left>right)
		{

			vector<string> tmp;
			string str(right+1,'.');
			for(int k=0; k<= right;k++){
				str[row[k]] = 'Q';
				tmp.push_back(str);
				str[row[k]] = '.';
			}


			res.push_back(tmp);
			return;

		}


		for(int i=0; i <=right; i++){

			bool ok = column[i]==0 && diagonal[left+i] ==0 && antidiagonal[left-i+right+1] == 0;
			if(!ok) continue;
			row[left] = i;
			column[i] = diagonal[left+i] = antidiagonal[left-i+right+1] = 1;
			solveNqueens(res,left+1,right);
			row[left] =0;
			column[i] = diagonal[left+i] = antidiagonal[left-i+right+1] = 0;



		}
	}


};




------------------------------------精简版  ---------------------------
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
        
        totalNQueens(0,n-1);
        
        
        return res;
    }
    
    
    void totalNQueens(int left, int right){
        if(left>right){
            res++;
        }
        for(int i=0;i<=right;i++){
            if(column[i]==1||diagonal[left+i]==1||antidiagonal[left-i+right+1]==1){
                continue;
            }
            row[left]=i;
            column[i]=diagonal[left+i]=antidiagonal[left-i+right+1]=1;
            totalNQueens(left+1,right);
            row[left]=0;
            column[i]=diagonal[left+i]=antidiagonal[left-i+right+1]=0;
        }
                
    }
    
};


------------------使用STL next_permuttation()函数--------------------
	
class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        vector<int> row;
        for(int i=0;i<n;i++){
            row.push_back(i);
        }
        if(istrue(row)) res++; 
        while(next_permutation(row.begin(),row.end())){
            if(istrue(row)) res++;  
        }
        return res;
    }
    
    bool istrue(vector<int> row){ 
        int n = row.size();
        vector<int> diagonal(2*n,0);
        vector<int> antidiagonal(2*n,0);
        for(int i=0;i<n;i++){
            if(diagonal[i+row[i]]==1||antidiagonal[n+i-row[i]]==1) return false;
            diagonal[i+row[i]]=antidiagonal[n+i-row[i]]=1;
        }
        return true;
    }
    
 
    
};

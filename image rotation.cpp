class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        for (int i=0; i<matrix.size()-1;i++)
        for(int j=i;j<matrix.size()-1-i;j++){
            tmp=matrix[i][j];
            matrix[i][j]=matrix[matrix.size()-1-j][i];
            matrix[matrix.size()-1-j][i]=matrix[matrix.size()-1-i][matrix.size()-1-j];
            matrix[matrix.size()-1-i][matrix.size()-1-j]=matrix[j][matrix.size()-1-i];
            matrix[j][matrix.size()-1-i]=tmp;
            
        }
        
    }
};
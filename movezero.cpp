class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int m=nums.size();
        while(nums[m-1]==0){
            m--;
        }
        while(i<m){
            if(nums[i]!=0){
                i++;
            }
            else{
                for (int j=i;j+1<m;j++)
                swap(nums[j],nums[j+1]);
                m--;
            }
        }
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(nums[i]+nums[j]!=target){
            j--;
            if(i==j){i++;j=nums.size()-1;}
        }
        vector<int> vec;
        vec.push_back(i);
        vec.push_back(j);
        return vec;
        
    }
};
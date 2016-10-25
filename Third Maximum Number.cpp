class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> index;
        for(int i=0;i<nums.size();i++){
            if(index.size()<3||nums[i]>*index.begin()) 
            {  
                index.insert(nums[i]);
                if(index.size()>3)
                index.erase(*index.begin());
            }
        }
        
        
        if(index.size()<3) return *max_element(index.begin(),index.end());
        
        return *index.begin();
        
            
        }
        
        
          
    
};
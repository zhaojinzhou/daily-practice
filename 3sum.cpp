
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int> > res;
        vector<int> num;
        int sum;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) return res;
            if(i>0&&nums[i]==nums[i-1]) continue;


            for(int j=i+1;j<nums.size();j++){

                if(nums[i]+nums[j]>0) break;

                for(int k=j+1;k<nums.size();k++){
                    sum=nums[i]+nums[j]+nums[k];

                    if(sum==0) {
                    num.push_back(nums[i]);
                    num.push_back(nums[j]);
                    num.push_back(nums[k]);
                    
                    if(res.size()==0||res[res.size()-1]!=num)
                    res.push_back(num);
                    num.clear();
                    }
                    if(sum>0)break;
                }


            }

        }



        return res;

    }
};


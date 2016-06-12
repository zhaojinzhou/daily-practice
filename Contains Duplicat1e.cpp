class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> tmp;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
        {
            tmp[*it]++;
            if(tmp[*it]==2) return true;
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> tmp;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
        {
            if(!tmp.insert(*it).second) return true;
        }
        return false;
    }
};
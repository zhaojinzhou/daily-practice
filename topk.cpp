class Solution {
public:
    static bool cmp( pair<int ,int> &x,  pair<int , int> &y)  {
        return x.second>y.second;
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int ,int > tmp;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            tmp[*it]++;
        }
        vector<pair<int,int> > tmp1(tmp.begin(),tmp.end());
        sort(tmp1.begin(),tmp1.end(),cmp);
        int j=0;
        vector<int> tmp2;
        vector<pair<int,int> > ::iterator it1=tmp1.begin();
        while(j<k){
            tmp2.push_back((*it1).first);
            it1++;j++;
            
        }
        return tmp2;
        
    }
};
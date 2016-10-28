class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,tmpsum=0;
        
        for(int i=0;i<prices.size();i++){
            if(i<(prices.size()-1)&&prices[i+1]>prices[i]) sum+=prices[i+1]-prices[i];
            }
            
       
        return sum;
    }
};
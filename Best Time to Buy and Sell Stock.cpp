class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=10000;
        int sum=0,tmpsum=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mi) {
                mi=prices[i];
                if(sum>tmpsum)tmpsum=sum;
                
            }
            
            if(prices[i]-mi>sum)
            sum=prices[i]-mi;
            
            
        }
        
        return max(tmpsum,sum);
        
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1) return 0;
        vector<int> f(prices.size(),0);
        vector<int> g(prices.size(),0);
        int iMin=100000;
        int sum=0;
        for(int i=0;i<prices.size();i++){
            iMin=min(iMin,prices[i]);
            if((prices[i]-iMin)>=sum){
                sum=(prices[i]-iMin);
                
            }
            f[i]=max(f[i-1],(prices[i]-iMin));
            f[i]=sum;
        }
        int iMax=-10000;
        sum=0;
        for(int i=prices.size()-1;i>=0;i--){
            iMax=max(iMax,prices[i]);
            if((iMax-prices[i])>=sum){
                sum=(iMax-prices[i]);
                
            }
            
           g[i]=sum;
        }
        sum=0;
        for(int i=0;i<prices.size();i++){
            sum=max(sum,f[i]+g[i]);
        }
        
        return sum;
    }
};
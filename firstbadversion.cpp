// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int up=n;
        int low=1;
        int mid=low+(up-low)/2;
        int sum;
        if (isBadVersion(low)==1)
        return low;
        
       while(low<up){
           sum=isBadVersion(mid)+isBadVersion(mid-1);
           if(sum==1)return mid;
           else{
               if(sum<1) {
                   low=mid+1;
               }
               else{
                   up=mid-1;
               }
            mid=low+(up-low)/2;
           }
       }
       return low;
            
        
    }
};
class Solution {
public:
    bool isPowerOfFour(int num) {
        
        int x=0x55555555;
        return (((num&(num-1))==0)&&(num&x));
        
    }
};
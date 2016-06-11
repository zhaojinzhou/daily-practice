class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a=0x80000000;
        uint32_t i=1;
        uint32_t sum=0;
        bool b;
        for(int j=0;j<32;j++){
            b=(n&a);
            sum+=(b)*i;
            i*=2;
            a=a>>1;
        }
        
        
        return sum;
        
    }
};
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int wid;
        if (A>E&&A>G&&C>E&&C>G)return (abs(C-A)*abs(D-B)+abs(E-G)*abs(F-H));
        if (A<E&&A<G&&C<E&&C<G)return (abs(C-A)*abs(D-B)+abs(E-G)*abs(F-H));
        
        if (B>F&&B>H&&D>F&&D>H)return (abs(C-A)*abs(D-B)+abs(E-G)*abs(F-H));; 
        if (B<F&&B<H&&D<F&&D<H)return (abs(C-A)*abs(D-B)+abs(E-G)*abs(F-H));;
        int a[]={A,C,E,G};
        int b[]={B,F,H,D};
        sort(a,a+sizeof(a)/sizeof(*a));
        sort(b,b+sizeof(b)/sizeof(*b));
        return (abs(C-A)*abs(D-B)+abs(E-G)*abs(F-H))-(a[2]-a[1])*(b[2]-b[1]);
        
        
        
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        int tmp=0;
        int tmp1;
        int tmp2;
        string a1;
        string sum;
        while(i>=0&&j>=0){
            if(a[i]=='1') tmp1=1;
            else tmp1=0;
            if(b[j]=='1') tmp2=1;
            else tmp2=0;
            
            if((tmp1+tmp2+tmp)%2==0)
            a1="0";
            else a1="1";
            sum.insert(0,a1);
            tmp=(tmp1+tmp2+tmp)/2;
            i--;
            j--;
            
        }
        while(i>=0){
            if(a[i]=='1') tmp1=1;
            else tmp1=0;
            if((tmp1+tmp)%2==0)
            a1="0";
            else a1="1";
            sum.insert(0,a1);
            tmp=(tmp1+tmp)/2;
            i--;
        }
        while(j>=0){
            if(b[j]=='1') tmp2=1;
            else tmp2=0;
            if((tmp2+tmp)%2==0)
            a1="0";
            else a1="1";
            sum.insert(0,a1);
            tmp=(tmp2+tmp)/2;
            j--;
        }
        if(tmp==1) sum.insert(0,"1");
        return sum;
        
    }
};
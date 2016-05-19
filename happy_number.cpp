class Solution {
public:
    vector<int> vec;
    
    bool isHappy(int n) {
        int sum=0;
       if(n<1)return false;
        while(n!=0){
			sum=(int)pow(n%10,2)+sum;
            n=n/10;
         
        }
       
        cout<<sum<<endl;
        if (1==sum){
        return true;	
        } 
        else{
        	
            if (find(vec.begin(),vec.end(),sum)==vec.end()){
                vec.push_back(sum);
                if(isHappy(sum)){
                return true;
                }
                else{return false;}
            }
            else{
                return false;
            }
        }
       
    }
};
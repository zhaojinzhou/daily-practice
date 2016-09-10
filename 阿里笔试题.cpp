#include <iostream>
#include <string>
using namespace std;

string triple(string &str){
    int index1=0,index2=1;
    while(index2<str.size()){
        if(str[index2]==str[index1]){
            index2++;
        if(index2==str.size()&&index2-index1>=2){
                str.erase(index1,(index2-index1+1));
                index1=(index1>=2)?(index1-2):0;
                index2=index1+1;

        }
        }
        else{
            if(index2-index1<2){
                index1=index2;
                index2++;
            }
            else{
                str.erase(index1,(index2-index1+1));
                index1=(index1>=2)?(index1-2):0;
                index2=index1+1;
            }
        }

    }



    return str;


}

using namespace std;

int main()
{
    string str;
    cin>>str;
    string res=triple(str);
    cout<<res;
    return 0;
}

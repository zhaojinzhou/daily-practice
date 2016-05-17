#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector <int> countBits(int num) {
        vector <int > a(num+1);
        int i;
        int tmp; 
		for (int j=0;j<=num;j++){
        i=0;
        tmp=j;
        while(tmp!=0){i++; tmp=tmp&(tmp-1);}
            a[j]=i;
        }
        return a;
    }



int main(int argc, char *argv[])
{

	vector <int >b;
	b=countBits(15);
	for (int i=0;i<=15;i++){cout<<b[i];} 
	return 0;
}
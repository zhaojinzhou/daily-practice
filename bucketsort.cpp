#include <iostream>
#include <iterator>
using namespace std;
int radix(int a[], int size){
	int radix=1;
	for (int i=0;i<size;i++){
		while(radix<=a[i]/10)
		radix*=10;
	}
	return radix;
	
} 


void radixsort(int a[],int size){
	int maxdex=radix(a, size);
	int radix=1;
	int tmp[size];
	int count[10];
	while(radix<=maxdex){
		for(int i=0;i<10;i++)
		count[i]=0;
		for(int i=0;i<size;i++)
		count[(a[i]/radix)%10]++;
		for(int i=1;i<10;i++)
		count[i]+=count[i-1];
		for(int i=size-1;i>=0;i--){
			tmp[count[(a[i]/radix)%10]-1]=a[i];
			count[(a[i]/radix)%10]--;
		}
		for(int i=0;i<size;i++)
		a[i]=tmp[i];
		 
		radix*=10;
	}
}

int main(int argc, char *argv[])
{
	int a[]={1,2,1,1,1,10,98,8,7,5,4,4,432,32,2,2,1,10,100,10000,100000,23}	;
	radixsort(a,sizeof(a)/sizeof(*a));
	ostream_iterator<int> it(cout," ");
	copy(a,a+sizeof(a)/sizeof(*a),it);
	
	return 0;
}
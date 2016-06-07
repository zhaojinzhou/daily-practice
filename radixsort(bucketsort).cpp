#include <iostream>
#include<iterator> 
using namespace std;
int maxdex(int a [],int size){
	int p=0;
	int b=1;
	for (int i=0;i<size;i++){
		while(a[i]>b){
			b*=10;
			p++;
		}
		
	}
//	cout<<p<<endl;
	return p;
}
void radixsort(int a[],int size	){
	int p=maxdex(a,size);
	int tmp [size];
	int count[10];
	int radix=1;
	for (int i=0;i<p;i++)
	{
		for (int j=0;j<10;j++)
		count[j]=0;
		for(int j=0;j<size;j++)
		{
			count[(a[j]/radix)%10]++;
		}
		for (int j=1;j<10;j++){
			count[j]=count[j-1]+count[j]; 
		} 
		for (int j=size-1;j>=0;j--){
			tmp[count[(a[j]/radix)%10]-1]=a[j];
			count[(a[j]/radix)%10]--;
		}
		for(int j=0;j<size;j++){
			a[j]=tmp[j];
		}
		radix*=10;

	}
	}
int main(int argc, char *argv[])
{
int a[]={1,3,4,4,54,6545645,7465,8,76,986,98765,774456,123,254,352,543,532,5,235};
		//quicksort(a,0,sizeof(a)/sizeof(*a)-1);
		radixsort(a,sizeof(a)/sizeof(*a));
		ostream_iterator<int> it(cout," ");
		copy(a,a+sizeof(a)/sizeof(*a),it);
	return 0;
}
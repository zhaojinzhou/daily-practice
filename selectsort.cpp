#include <iostream>
using namespace std;
int ofmax(int a[], int size){
 int max=0;
 int index=0;
 for (int i=0;i<size;i++ )
 	if (a[i]>max)
	{
	max=a[i];
	index=i;	
		
	} 
	return index;
}
void selectsort(int a[], int size){
	while(size>0){
		swap(a[ofmax(a,size)],a[size-1]);
		size--;
	}
	
}

 
int main(int argc, char *argv[])
{
	int a[]={1,2,3,7,8,9,5,4,32,36666,2,1,2,3,4,5,6,7,8,9,0,34,23};
	selectsort(a,sizeof(a)/sizeof(*a));
	for (int i=0;i<sizeof(a)/sizeof(*a);i++)
	cout<<a[i]<<' ';
	return 0;
}
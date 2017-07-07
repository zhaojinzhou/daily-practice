#include<iostream>
#include<malloc.h>
using namespace std;

void shellsort( int a[], int size){
	int i,j,gap;
	for (gap=size/2;gap>0;gap/=2)
		for (j=gap;j<size;j++)
			for (i=j-gap;i>=0&&a[i]>a[i+gap];i-=gap)
				swap(a[i],a[i+gap]);
			}
	
		
int main (){
int a[]={1,765,7,76,87,9,0,6,5,4,4,4,4,3,45556,23};

shellsort(a, sizeof(a)/sizeof(*a)); 
for (int i=0;i<sizeof(a)/sizeof(a[0]);i++)
cout<<" "<<a[i];


	return 0;
} 

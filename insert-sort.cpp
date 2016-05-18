#include<iostream>
using namespace std;
void insertsort(int a[],int size){
	for (int i=0;i<size;i++)		
		for (int j=i-1;j>=0&&a[j]>a[j+1];j--)
			swap(a[j],a[j+1]);
} 
	
int main(){
	
int a[]={1,6,7,8,9,3,1,1,1,1,1,1,1,1,1,1,1,1,4,5,32,4,5,6,8,9,7,4,3};
insertsort(a,sizeof(a)/sizeof(a[0]));
for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)cout<<a[i]<<" "; 	
	return 0;
} 
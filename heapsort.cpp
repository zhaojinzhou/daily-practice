#include <iostream>
#include<algorithm>
using namespace std;

void heapfilter(int a[],int start,int size	){
	int j=start*2+1;
	while (j+1<size){
		if (a[start]<a[j]&&a[start]<a[j+1])return;
		if (a[j]<a[j+1]){
			swap(a[start],a[j]);
			start=j;
		}
		else{
			swap(a[start],a[j+1]);
			start=j+1; 
		} 
		j=2*start+1;
	}
	if (j<size&&a[start]>a[j])swap(a[start],a[j]);
}

void heapsort(int a[], int size){
	while(size>0){
		for (int i=(size-2)/2;i>=0;i--){
			heapfilter(a,i,size);
		}
		swap(a[0],a[size-1]);
		size--; 
	}
}

 


int main(){
	
int a[]={1,6,7,8,9,3,1,1,1,1,1,1,1,1,1,1,1,1,4,5,32,4,5,6,8,9,7,4,3};
heapsort(a,sizeof(a)/sizeof(a[0]));
for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)cout<<a[i]<<" "; 	
	return 0;
} 
#include <iostream>
using namespace std;

void Mergearray( int a[],int left, int mid, int right,int tmp[]){
	int i=left,j=mid+1,k=0;
	while(i<=mid&&j<=right){
		if(a[i]<=a[j])tmp[k++]=a[i++];
		if(a[i]>a[j])tmp[k++]=a[j++];
	} 
	while(i<=mid){
		tmp[k++]=a[i++];
	}
	while(j<=right){
		tmp[k++]=a[j++];
	}
	for(int i=0;i<k;i++)
	a[left+i]=tmp[i];
	
}	
 
void mergesort(int a[],int start,int end ,int tmp[]){
	int mid=(start+end)/2;
	if (start<end){
		mergesort(a,start,mid,tmp);
		mergesort(a,mid+1,end,tmp);
		Mergearray(a,start,mid,end,tmp);
	}
} 
void Mergesort(int a[], int size ){
	int *p=new int [size];
	mergesort(a,0,size-1,p);
	delete [] p;
	p=NULL;
}
		
			

	
		

	
		
int main (){
int a[]={1,765,7,76,87,9,0,6,5,4,4,4,4,3,45556,23};

Mergesort(a, sizeof(a)/sizeof(*a)); 
for (int i=0;i<sizeof(a)/sizeof(a[0]);i++)
cout<<" "<<a[i];


	return 0;
} 
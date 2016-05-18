#include <iostream>
using namespace std;
void quicksort(int a[], int left,int right){
	if(left>right)return;
	int i=left,j=right,tmp=a[left];
	while(i!=j){
		while(i<j&&a[j]>=tmp){
			j--;
		}
		while(i<j&&a[i]<=tmp){
			i++;
		}
		if (i<j)swap(a[i],a[j]);
	}
	a[left]=a[i];
	a[i]=tmp;
	quicksort(a,left,i-1);
	quicksort(a,i+1,right); 
} 


int main (){
int a[]={1,765,7,76,87,9,0,6,5,4,4,4,4,3,45556,23};

quicksort(a,0, sizeof(a)/sizeof(*a)-1); 
for (int i=0;i<sizeof(a)/sizeof(a[0]);i++)
cout<<" "<<a[i];


	return 0;
} 
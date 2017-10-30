//#include "header.h"	//AnycodeX includes the header.h by default, needn't cancle the notation.
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iterator>
using namespace std;
#define SIZE (20)

class quicksort{
    void sort(int a[SIZE], int left, int right);
    public:
    void sort(int a[SIZE], int size);
};

void quicksort::sort(int a[SIZE], int left, int right){
    if(left>right) return;
    int i= left, j = right;
    while(i<j){
        while(i<j&&a[j]>=a[left])j--;
        while(i<j&&a[i]<=a[left])i++;
        if(i<j) swap(a[i],a[j]);   
    }
    swap(a[left],a[i]);
    sort(a,left,i-1);
    sort(a,i+1,right);
}

void quicksort::sort(int a[SIZE], int size){
    sort(a,0,size-1);
}

class testcase_for_quicksort{
    public:
    static void test(quicksort& input){
        srand(time(NULL));
        int a[SIZE];
        for(int i=0;i<SIZE;i++){
            a[i] = rand()%200;
        }
        ostream_iterator<int> it(cout," ");
        copy(a,a+SIZE,it);
        cout<<endl;
        input.sort(a,SIZE);
        copy(a,a+SIZE,it);
    }
};


int main()
{
    quicksort solution;
    
    testcase_for_quicksort::test(solution);
	return 0;
}

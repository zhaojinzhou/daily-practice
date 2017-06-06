#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct node{
	node* next;
	int val;
} node;
//void reverse(*node)

int main()
{
	srand(time(NULL));
	node head;
	node* tmp1=&head;
	node* tmp=&head;
	head.val=0;
	for(int i=0;i<10;i++){
		node *newnode = new node;
		newnode->val=rand()%100;
		cout<<newnode->val<<'\t';
		tmp->next=newnode;
		tmp=tmp->next;
		tmp->next=NULL;

	}
	cout<<endl;
   	for(int i = 0; i < 11; i++){
		cout<<tmp1->val<<'\t';
		tmp1=tmp1->next;
	}
	cout<<endl;
	return 0;
}

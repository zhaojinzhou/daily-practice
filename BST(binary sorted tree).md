    
    #include <math.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <iostream>
    using namespace std;

//结构体定义：  

    struct BiTree {
      int data;
      BiTree *lchild;
      BiTree *rchild;
    };  
    
//在二叉排序树中插入查找关键字key  


    BiTree* InsertBST(BiTree *t,int key)
    {
      if (t == NULL)
      {
        t = new BiTree();
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t;
      }

      if (key < t->data) 
        t->lchild = InsertBST(t->lchild, key);
      else
        t->rchild = InsertBST(t->rchild, key);

      return t;
    }  

//n个数据在数组d中，tree为二叉排序树根  

    BiTree* CreateBiTree(BiTree *tree, int d[], int n)
    {

        tree = InsertBST(tree, 8);
      for (int i = 0; i < n; i++)
        InsertBST(tree, d[i]);
      return tree;
    }


    void pretraversal(BiTree *head){
      if(head == NULL) return;

      pretraversal(head->lchild);
      cout<<"\t"<<head->data;

      pretraversal(head->rchild);


    }  
   
   

    #define SIZE 20

    int main()
    {
      int d[SIZE];
      srand(time(NULL));
      for(int i =0 ;i<SIZE;i++){
        d[i] = rand()%100;
      }
      BiTree * head= NULL;

      head = 	CreateBiTree(head, d,20);
      pretraversal(head);
    //	getchar();
      return 0;
    }

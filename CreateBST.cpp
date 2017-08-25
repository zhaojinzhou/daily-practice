#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iterator>

using namespace std;
class TreeNode{
    public:
        TreeNode* left;
        TreeNode* right;
        int val;
        TreeNode(int input):val(input),left(NULL),right(NULL){}
        
};

TreeNode* InsertTreeNode(TreeNode* head, int val){
    if(head == NULL){
        head = new TreeNode(val);
        return head;
    }
    if(val < head->val){
        head->left =InsertTreeNode(head->left ,val); 
    }
    else{
        
        head->right =InsertTreeNode(head->right ,val);
    }
}

TreeNode* CreateBST(TreeNode* head,int input[],int size){
    for(int i  =0;i<size;i++){
        head = InsertTreeNode(head,input[i]);
    }
    return head;
}

void Traversal(TreeNode* head){
    if(head ==NULL) return;
    cout<<head->val<<" ";
    Traversal(head->left);
    Traversal(head->right);
}
void TraversalMid(TreeNode* head){
    if(head ==NULL) return;
 
    TraversalMid(head->left);
       cout<<head->val<<" ";
    TraversalMid(head->right);
}
void TraversalPost(TreeNode* head){
    if(head ==NULL) return;
    TraversalPost(head->left);
    TraversalPost(head->right);
       cout<<head->val<<"\t";
}

#define SIZE 20
int main(){
    srand(time(NULL));
    int input[SIZE];
    for(int i =0;i<SIZE;i++)
        input[i] = rand()%200;
    ostream_iterator<int> output(cout, " ");
    copy(input, input+SIZE,output);
    cout<<endl;
    TreeNode* head = NULL;
    head = CreateBST(head, input,SIZE);
    TraversalMid(head);
    



}

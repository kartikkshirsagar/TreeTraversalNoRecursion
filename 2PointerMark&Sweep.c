#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_Node
{
    int data;
    struct Tree_Node* left;
    struct Tree_Node* right;
    int visited;
}treeNode;


/*void InitTree(treeNode* root){
    if(root!=NULL)
    {
        root->visited=0;
        InitTree(root->left);
        InitTree(root->right);
    }
}*/

void MarkTree(treeNode* root)
{
    if(root==NULL)
    {
        return;
    }
   treeNode* curr,*pre_node;
   curr=root;
   while(curr!=NULL)
   {
       if(curr->left==NULL)
       {
           curr->visited=1;
           printf("Node with %d data visited\n",curr->data);
           curr=curr->right;
       }
       else{
            pre_node=curr->left;
            while(pre_node->right!=NULL && pre_node->right!=curr)//FINDING THE PREDECESSOR
            {
                pre_node=pre_node->right;
            }
            if(pre_node->right==NULL)
            {
                pre_node->right=curr;
                curr=curr->left;
            }
            else if(pre_node->right==curr)
            {
                pre_node->right=NULL;
                curr->visited=1;
                printf("Node with %d data visited\n",curr->data);
                curr=curr->right;
            }

        }
    }
}        

treeNode* newtNode(int data) 
{ 
    treeNode* node = (treeNode*)malloc(sizeof(treeNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->visited=0;
  
    return (node); 
} 
int main(){
    treeNode* root = newtNode(1); 
    root->left = newtNode(2); 
    root->right = newtNode(3); 
    root->left->left = newtNode(4); 
    root->left->right = newtNode(5); 
    MarkTree(root);
}


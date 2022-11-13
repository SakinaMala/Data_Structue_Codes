#include <stdio.h>
#include <stdlib.h>
struct Node{
 int data;
 struct Node* left;
 struct Node* right;
};
struct Node* newNode(int data){
 struct Node* node=(struct Node*)
 malloc(sizeof(struct Node));
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return(node);
}
void mirror(struct Node* node){
 if(node==NULL)
 return;
 else{
 struct Node* temp;
 mirror(node->left);
 mirror(node->right);
 temp=node->left;
 node->left=node->right;
 node->right=temp;
 }
}
int countnodes(struct Node*root){
 int count=0;
 if(root!=NULL){
 count++;
 countnodes(root->left);
 count++;
 countnodes(root->right);
 count++;
 count++;
 }
 count++;
 return count;
}
struct Node *cloneBinaryTree(struct Node *root){
 if(root==NULL)
 return NULL;
 struct Node *New=newNode(root->data);
 New->left=cloneBinaryTree(root->left);
 New->right=cloneBinaryTree(root->right);
 return New;
}
void inOrder(struct Node* node){
 if(node==NULL)
 return;
 inOrder(node->left);
 printf("%d",node->data);
 inOrder(node->right);
}
int main(){
 struct Node *clone;
 struct Node *root=newNode(1);
 root->left=newNode(2);
 root->right=newNode(3);
 root->left->left=newNode(4);
 root->left->right=newNode(5);
 printf("Inorder Traversal of the Constructed Tree is\n");
 inOrder(root);
 mirror(root);
 printf("\nInorder Traversal of the Mirror Tree is\n");
 inOrder(root);
 clone=cloneBinaryTree(root);
 printf("\nInorder Traversal of the Clone Tree is\n");
 inOrder(clone);
 printf("\nNumber of Nodes in Tree = %d\n",countnodes(root));
 return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *create();
void preorder(struct node* root){
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}


int main() {
    struct node *root;
    printf("\nEnter data( -1 for no node) :");
    root=create();
    printf("\n\nPreorder is: \t");
    preorder(root);
    printf("\nInorder is: \t");
    inorder(root);
    printf("\nPostorder is: \t");
    postorder(root);


    return 0;
}

//Data for sample input
int elmts[]={4,5,7,-1,-1,8,-1,-1,10,-1,1,-1,-1};
int i=0;

struct node *create() {
    struct node* new_node;
    int x;
    new_node=(struct node*) malloc(sizeof(struct node));

    scanf("%d",&x);

//    --------TO automate creation and populate the tree with the sample data and not give user input uncomment this section----
    /*x=elmts[i];
    i++;
    printf("%d",x);*/
//    -----------------------

    if(x==-1)
        return NULL;

    new_node->data=x;

    //We will keep reading the left node till the leaf nodes
    printf("\nEnter the left child of %d :",x);
    new_node->left=create();

    //Once we reach the leaf, we will move up levels and read the right nodes
    printf("\nEnter the right child of %d :",x);
    new_node->right=create();

    //At the end we will return the top root node and will store in a variable

    return new_node;
}

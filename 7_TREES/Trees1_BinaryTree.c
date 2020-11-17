//Binary Tree C Program
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueT.h"
#include "StackT.h"

struct Node *root=NULL;

void Create_BTree()
{
    struct Node *ptr,*temp;
    int x;
    struct Queue q;
    create(&q,25);
    printf("\n Enter root value : ");
    scanf("%d",&x);

    root=(struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        ptr=dequeue(&q);
        printf("\n Enter left child of %d : ",ptr->data);
        scanf("%d",&x);
        if(x!=-1)
       {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=x;
        temp->lchild=temp->rchild=NULL;
        ptr->lchild=temp;
        enqueue(&q,temp);
       }

        printf(" Enter right child of %d : ",ptr->data);
        scanf("%d",&x);
        if(x!=-1)
       {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=x;
        temp->lchild=temp->rchild=NULL;
        ptr->rchild=temp;
        enqueue(&q,temp);
       }
    }
}
struct Node* new_node(int nkey)
{       struct Node *temp;
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=nkey;
        temp->lchild=temp->rchild=NULL;
        return temp;
}
void Insert_LO(struct Node *root) //Insert any node within already created tree.
{   int key;
    printf("\n\n Enter value to insert in the tree : ");
    scanf("%d",&key);
    printf("\n\n ");
    struct Queue q;
    create(&q,25);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);

        if(root->lchild)
        {
            //printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            //printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
        if((root->lchild)==NULL)
        {
            root->lchild = new_node(key);
            break;
        }
        if((root->rchild)==NULL)
        {
            root->rchild = new_node(key);
            break;
        }
    }
}
void Delete_LO(struct Node *root)  //this is incomplete and ambiguous func
{   int key;
    printf("\n\n Enter value to delete in the tree : ");
    scanf("%d",&key);
    printf("\n\n ");
    struct Queue q;
    create(&q,25);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->data==key)
        {
            printf(" Deleting the %d ",root->data);
            if((root->rchild)!=NULL)
            {
                 root=root->rchild;
                 root->rchild=NULL;
                 printf(" Coming out now");
                 break;

            }
        }
        if(root->lchild)
        {
            //printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            //printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }

    }
}
/*
void insert(struct Node* ptemp, int key)
{
    queue<struct Node*> q;
    q.push(temp);

    // Do level order traversal until we find
    // an empty place.
    while (!q.empty())
    {
        struct Node* temp = q.front();
        q.pop();

        if (!temp->left) //if temp->left is null
        {
            temp->left = newNode(key);
            break;
        }
        else
            q.push(temp->left);

        if (!temp->right)
        {
            temp->right = newNode(key);
            break;
        }
        else
            q.push(temp->right);
    }
}
*/
void PreOrder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(struct Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        printf("%d ",p->data);
        InOrder(p->rchild);
    }
}
void PostOrder(struct Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d ",p->data);
    }
}

void IPreOrder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,50);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInOrder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,50);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}
/*
void IPostOrder(struct Node *p)
{
    struct Stack stk;
    long int temp;
    struct Node *g;
    Stackcreate(&stk,50);

    while(p!=NULL || !isEmptyStack(stk))
    {
        if(p!=NULL)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {   temp=pop(&stk);
            if(temp>0)
            {
              push(&stk,-temp);
              g = (Node*)temp;
              p=g->rchild;
             // p=((Node*)temp)->rchild;
            }
            else
            {
              printf("%d ",((Node*)temp)->data);
              p = NULL;
            }
        }
    }
}
*/
void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q,25);
    printf("%d ",root->data);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);

        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root)
    {
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;

    if(root==0)
    { return 0; }

    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}
/*below printGivenLevel() Func is called by reverseLevelOrder()
 Print nodes at a given level */
void printGivenLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        {
            printf(" %d ",root->data);
            return;
        }
    else if (level > 1)
    {
        printGivenLevel(root->lchild, level-1);
        printGivenLevel(root->rchild, level-1);
    }
}
void reverseLevelOrder(struct Node *root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}

void mirror(struct Node* root)
{
    if (root == NULL)
        return;
    else
    {
        struct Node* temp;

        /* do the subtrees */
        mirror(root->lchild);
        mirror(root->rchild);

        /* swap the pointers in this node */
        temp     = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
}

bool isBalanced(struct Node* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    /*if (root == NULL)
        return true;
    */
    /* Get the height of left and right sub trees */
    lh = height(root->lchild);
    rh = height(root->rchild);

    if (abs(lh - rh) < 1 && isBalanced(root->lchild) && isBalanced(root->rchild))
        {return true;}

    /* If we reach here then
    tree is not height-balanced */
    return false;
}

void InOrderSucc(struct Node *p)  //Function to Find Inorder Successor of any given input node
{   int node_data;
    printf("\n Enter any node to find it's Inorder Successor :");
    scanf("%d",&node_data);
    struct Stack stk;
    Stackcreate(&stk,50);

    while(p || !isEmptyStack(stk))
    {
        if(p->data == node_data)
        {
            if(p->rchild != NULL)
            {   p=p->rchild;
                printf("\n Inorder Successor of given node is : %d ",p->data );
                break;
            }
            if(p->rchild == NULL)
            {   if(!isEmptyStack(stk))
                { p=pop(&stk); }
                printf("\n Inorder Successor of given node is : %d ",p->data );
                break;
            }
        }
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }

}

void nth_InOrder(struct Node *p, int nth ) //Function to Find n-th node of inorder traversal
{   static int node_count =0;

    if(p && node_count<= nth)
    {
        nth_InOrder(p->lchild, nth);
        node_count++;
        if(node_count == nth )
        {
            int save=p->data;
            printf("\n Thus, %d th node of inorder traversal is  : %d ",nth,save);

        }
        nth_InOrder(p->rchild, nth);
    }

}


int main()
{
    Create_BTree();
    printf("\n\n");

    printf("\n\n Level Order Traversal : ");
    LevelOrder(root);
    printf("\n\n");

    /*
    printf("\n\n Enter nth node of inorder traversal : ");
    int node_nth ;
    scanf("%d",&node_nth);
    printf("\n  ");
    nth_InOrder(root,node_nth); //func call
    printf("\n\n");


    printf("\n\n InOrder Successor in Binary Tree : \n");
    InOrderSucc(root);
    printf("\n\n");

    printf("\n\n Reverse Level Order Traversal : ");
    reverseLevelOrder(root);
    printf("\n\n");

    printf("\n\n Pre Order Traversal :  ");
    PreOrder(root);

    printf("\n\n In Order Traversal : ");
    InOrder(root);

    printf("\n\n Post Order Traversal : ");
    PostOrder(root);

    printf("\n\n Iterative Pre Order Traversal : ");
    IPreOrder(root);

    printf("\n\n Iterative In Order Traversal : ");
    IInOrder(root);

    printf("\n\n Deletion of a node : ");
    Delete_LO(root);

    printf("\n\n Level Order Traversal : ");
    LevelOrder(root);

    printf("\n\n Count of Nodes in a Tree : %d ",count(root));

    printf("\n\n Height of Tree : %d  ",height(root));

    printf("\n\n Mirror of Tree : ");
    mirror(root);

    printf("\n\n To check If Tree is balanced :- ");
    bool res = isBalanced(root);
    if(res==true){ printf("\n Yes Balanced\n\n");}
    else{printf("\n Tree not Balanced\n\n");}


    */
    printf("\n\n\n\n\n\n\n\n");
    return 0;
}

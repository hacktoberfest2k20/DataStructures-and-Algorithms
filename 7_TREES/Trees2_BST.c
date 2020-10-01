//BST Insert and Search
#include <stdio.h>
#include <stdlib.h>
#include "QueueT.h"
/*
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
*/
struct Node *root=NULL;
void Insert(int key)
{
    struct Node *t=root;
    struct Node *r=NULL,*p;

    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
    return ;
    }

    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
             t=t->rchild;
        }
        else
        {
            return;
        }
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        { return t; }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return NULL;
}

struct Node *RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}


int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
    {
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);

    return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p)  //Inorder Predecessor where p = p->lchild is passed.
{                                   //This func is called from other function.
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}


struct Node *InSucc(struct Node *p)  //Inorder Successor p = p->rchild is passed.
{                                   //This func is called from other function.
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
    {
        return NULL;
    }

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);     // Inorder Predecessor is called here
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);    // Inorder Successor is called here.
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

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
int main()
{
    struct Node *temp;
    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);
    //Delete(root,30);
    printf("\n\n ");
    LevelOrder(root);
    printf("\n\n ");

    /*
    temp=Search(20);
    if(temp!=NULL)
    printf("\nElement %d is found\n",temp->data);
    else
    printf("\nElement is not found\n");
    */

    return 0;
}

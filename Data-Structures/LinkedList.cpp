/* Linked List
This is basic data structure which helps you to understand
the way of writing data structures. It may be basic but presents
many concepts of dynamic structures

Insert: O(n)
Find: O(n)
Delete: O(n)
Change Element: O(n)
Print: O(n)
*/

#include <bits/stdc++.h>

using namespace std;

struct LinkedList 
{
    int value;
    LinkedList *next;
    LinkedList(int val)
    {
        this->value=val;
        this->next=NULL;
    }
};

void Insert(LinkedList *&root, int value)
{
    if(root==NULL)
    {
        root=new LinkedList(value);
    }
    else
    {
        LinkedList *tmp = root;
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
        }
        tmp->next=new LinkedList(value);
    }
}
LinkedList* Find(LinkedList *root, int value)
{
    while(root!=NULL && root->value!=value)
    {
        root=root->next;
    }
    return root;
}
void Delete(LinkedList *&root, int value)
{
    if(root==NULL)return;
    if(root->value==value)
    {
        LinkedList *tmp = root;
        root=root->next;
        delete tmp;
    }
    LinkedList *tmp = root;
    while(tmp!=NULL && tmp->next!=NULL && tmp->next->value!=value)
    {
        tmp=tmp->next;
    }
    if(tmp!=NULL)
    {
        LinkedList *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp2;
    }
}
void Print(LinkedList *root)
{
    while(root!=NULL)
    {
        cout<<root->value<<" ";
        root=root->next;
    }
    cout<<endl;
}
int main()
{
    //Driver Code Lets test this
    LinkedList *root = NULL;
    Insert(root,5);
    Insert(root,6);
    Insert(root,10);
    Insert(root,9);
    Print(root);
    Delete(root,10);
    Print(root);
    cout<<Find(root,7)<<endl;
    cout<<Find(root,5)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node* next;

}*head;

void create_insert()
{
    int data;
    cout<<"\n Enter the value to be inserted at beginning : ";
    cin>>data;
    struct node *temp = new node;
    struct node *ptr=head;
    temp->info = data;
    temp->next = NULL;
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
           temp->next=ptr;
           head=temp;
    }
}
void insert_end()
{
    int data;
    cout<<"\n Enter the value to be inserted at end of the List : ";
    cin>>data;
    struct node *temp = new node;
    struct node *ptr=head;
    temp->info = data;
    temp->next = NULL;
    if(head==NULL)
    {
       head=temp;
    }
    else
    {      while(ptr->next!=NULL)
            {
             ptr=ptr->next;
            }
            ptr->next=temp;

    }
}

void insert_end2()  //this function is used to create a loop in the linked list.
{
    int pos=0;
    struct node *ptr=head, *save;

    if(head==NULL)
    {
       cout<<"\n Linked List is empty ";
    }
    else
    {      while(ptr->next!=NULL)
            { pos=pos+1;
              cout<<"\n Inside"<<pos;

              if(pos==3)
              {
                  save=ptr;
                  cout<<"\n Inside 3 again....Save->info ="<<save->info;
                  cout<<"\n";
              }

             ptr=ptr->next;
            }
            ptr->next=save;
            return;

    }
}


int ccount(struct node *p)
{
int cnt=0;
while(p)
{
cnt++;
p=p->next;
}
return cnt;
}
void insert_nth()
{
    int data,pos;
    cout<<"\n\n Enter the value to be inserted at nth position of the List : ";
    cin>>data;
    cout<<"\n Enter the position to insert the node: ";
    cin>>pos;
    struct node *temp = new node;
    struct node *ptr, *prev;
    ptr=head;
    temp->info = data;
    temp->next = NULL;
    if(head==NULL)
    {
       head=temp;
    }
    else if(pos == 1)
    {
       temp->next = head;
       head=temp;
    }
    else if(pos > ccount(head))
    {
       while(ptr->next!=NULL)
            {
             ptr=ptr->next;
            }
            ptr->next=temp;
    }
    else
    {    for(int i=1;i<pos;i++)
        {
            prev=ptr;
            ptr=ptr->next;
        }
         temp->next=ptr;
         prev->next=temp;

    }
}
void isSorted()
{   int flag=0;
    struct node *ptr=head;
    cout<<"\n Checking whether Linked List is sorted or not. ";
    if(head==NULL)
    {
       cout<<"\n Linked List is empty ";
    }
    else
    {      while(ptr->next!=NULL)
            {
                if((ptr->info) > (ptr->next->info) )
                {
                    flag=1;
                }
             ptr=ptr->next;
            }
            if(flag==1)
            {
                cout<<"\n\n Linked List is not sorted. \n\n";
            }
            else{
                cout<<"\n\n Linked List is sorted. \n\n";
            }
    }
}
void reverse_ptr()
{
    struct node *p=head, *q=NULL, *r=NULL;
    cout<<"\n Reversed the linked list. (Using Sliding Pointers) \n\n";
    if(head==NULL)
    {
       cout<<"\n Linked List is empty \n";
    }
    else
    {      while(p!=NULL)
            {   r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            head=q;
    }


}

void reverse_info()
{

    struct node *p=head; int arr[10]={0}; int i=0;

    cout<<"\n Reversed the linked list. (Using REVERSING node DATA method) \n\n";
    if(head==NULL)
    {
       cout<<"\n Linked List is empty \n";
    }
    else
    {      while(p!=NULL)
            {   arr[i]=p->info;
                p=p->next;
                i++;
            }
            p=head; i--;
            while(p!=NULL)
            {   p->info=arr[i];
                p=p->next;
                i--;
            }
    }
}
void remove_duplicate()
{
    struct node *prev=head, *ptr;
    ptr=prev->next;
    cout<<"\n Removing duplicates(if present) in the Linked List.\n (Assuming the Linked List is already sorted)\n\n";
    if(head==NULL)
    {
       cout<<"\n Linked List is empty \n";
    }
    else
    {      while(prev->next!=NULL)
            {
                if((prev->info) == (ptr->info) )
                {
                    prev->next=ptr->next;
                    free(ptr);
                    ptr=prev->next;
                }
                else
                {

                    prev=ptr;
                    ptr=ptr->next;
                }
            }
    }
}
void checkloop()
{
     int flag=0;
     struct node *p=head,*q;

    cout<<"\n To Check for loop in linked list.  \n\n";
    if(head==NULL)
    {
       cout<<"\n Linked List is empty \n";
    }
    else
    {      while(p->next!=NULL)
            {   q=q->next->next;
                p=p->next;
                if(p==q)
                {   flag=1;
                    break;
                }
            }

    }
    if(flag==1)
    {
        cout<<" Yes !! Loop exists in the linked list ";
    }
    else{
        cout<<" No !! There is no Loop in the linked list ";
    }


}
void display()
{
    struct node *temp;
    temp = head;
    cout<<"\n\n Elements of list are: "<<endl;
    cout<<"  ";
    while (temp != NULL)
    {   cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<"\n"<<endl;

}
void display2() //this function is used to print the loop created and  in the linked list.
{   int position=0;
    struct node *temp;
    temp = head;
    cout<<"\n\n Elements of list are: "<<endl;
    cout<<"  ";
    while (temp != NULL)
    {   position++;
        if(position==10)
              {

                  cout<<"\n Inside 10 now ........exiting.....";
                  break;
              }
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<"\n"<<endl;

}
/** **/

int main()
{
cout<<"Program to implement LINKED LISTS.\n\n\n";


return 0;
}

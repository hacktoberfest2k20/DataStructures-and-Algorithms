#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    struct node* next;

} *head;

void display()
{
    struct node *temp;
    temp = head;
    cout<<"\n  Elements of list are: "<<endl;
    cout<<"  ";
    while (temp != NULL)
    {   cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

void create_insert_front()
{
    int data;
    cout<<"\n  Enter the value to be inserted at beginning : ";
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
    cout<<"\n  Insertion at beginning successful. ";
    display();
}

void insert_end()
{
    int data;
    cout<<"\n  Enter the value to be inserted at end of the List : ";
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
    cout<<"\n  Insertion at end successful. ";
    display();
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
    cout<<"\n  Enter the position to insert the node : ";
    cin>>pos;
    cout<<"\n  Enter the value to be inserted at nth position of the List : ";
    cin>>data;

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
    cout<<"\n  Insertion successful. ";
    display();
}


void delete_front()
{   struct node *ptr;
    if (head == NULL)
    { cout<<"\n  List is Empty\n";
      return;
    }
    else
    {   ptr=head;
        head=ptr->next;
        delete ptr;
    }
    cout<<"\n  Element deletion at Beginning successful.\n"<<endl;
    display();
}

void delete_end()
{   struct node *ptr, *prev;
    ptr = head;
    if (head == NULL)
    { cout<<"\n  List is Empty\n";
       return;
    }
    if(ptr->next == NULL)
    {
        free(ptr);
        head=NULL;
    }
    else
    {
       while(ptr->next!=NULL)
        {   prev=ptr;
            ptr=ptr->next;
        }
        prev->next=NULL;
        free(ptr);
    }
        cout<<"\n  Element deletion at End successful.\n"<<endl;
    display();
}

void delete_nth()
{    int pos; int dcount=0; int flag=1;
    cout<<"\n  Enter the position to delete the node: ";
    cin>>pos;
    struct node *ptr, *prev;
    ptr = head;
    int ncount= ccount(head);
    //cout<<" Count of nodes :"<<ncount;
    if(pos>=ncount)
    {
      cout<<"\n  You have exceeded the limit. There is no node at the given position.\n";
      flag=0;
    }
    else if(head == NULL)
    { cout<<"  List is Empty\n";flag=0;
      return;
    }
    else if(ptr->next == NULL)
    {    dcount++;
        free(ptr);
        head=NULL;
    }
    else if(pos == 1)
    {  dcount++;
       head = ptr->next ;
       free(ptr);
    }
    else
    {       dcount++ ; // here below loop runs for n-1 times, that is why we incremented here for printing correct position number.
        for(int i=1;i<pos;i++)
        {   dcount++;
            prev=ptr;
            ptr=ptr->next;
        }
         prev->next=ptr->next;
         free(ptr);
    }
    if(flag==1)
    {
            cout<<"\n  Element deletion at position :"<<dcount<<" successful.\n"<<endl;
    }
    display();
}


void search()
{
    int value, cpos = 0;
    bool flag = false;
    if (head == NULL)
    {
        cout<<"  List is empty\n"<<endl;
        return;
    }
    cout<<"\n  Enter the value to be searched: ";
    cin>>value;
    struct node *ptr;
    ptr=head;
    while (ptr->next!= NULL)
    {
        cpos++;
        if (ptr->info == value)
        {
            flag = true;
            cout<<"\n  Element "<<value<<" is found at position "<<cpos<<endl;
        }
        ptr = ptr->next;
    }
    if (flag==0)
       {
            cout<<"\n  Element "<<value<<" not found in the list"<<endl;
       }
    display();
}


int main()
{
     int ppcount; int choice ;
     while (1)
    {
        cout<<endl<<"          ------------------------------------------------------"<<endl;
        cout<<endl<<"                   Operations on Singly linked list"<<endl;
        cout<<endl<<"          ------------------------------------------------------"<<endl;
        cout<<"                1.Create Node or Insert Node at beginning"<<endl;
        cout<<"                2.Insert Node at End"<<endl;
        cout<<"                3.Insert Node at any position(First/last/nth)"<<endl;
        cout<<"                4.Delete Node at beginning"<<endl;
        cout<<"                5.Delete Node at End"<<endl;
        cout<<"                6.Delete Node at any position(First/last/nth)"<<endl;
        cout<<"                7.Search any Element"<<endl;
        cout<<"                8.Display Linked List"<<endl;
        cout<<"                9.Count the number of nodes in the Linked List "<<endl;
        cout<<"                10.Exit \n"<<endl;
        cout<<"                Enter your choice : ";
        cin>>choice;
        cout<<"\n\n";
        switch(choice)
        {
        case 1:
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Inserting Node at Beginning: "<<endl;
            create_insert_front();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 2:
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Inserting Node at End: "<<endl;
            insert_end();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 3:
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Inserting Node at any position(First/last/nth): "<<endl;
            insert_nth();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 4:
            cout<<" -----------------------------------------------------------------------"<<endl;
            //cout<<"       Deleting Node at beginning: "<<endl;
            delete_front();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 5:
            cout<<" -----------------------------------------------------------------------"<<endl;
            //cout<<"       Deleting Node at End: "<<endl;
            delete_end();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 6:
            cout<<" -----------------------------------------------------------------------"<<endl;
            //cout<<"       Deleting Node at any position(First/last/nth) : "<<endl;
            delete_nth();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 7:
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Searching element in Linked List: "<<endl;
            search();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 8:
            cout<<" -----------------------------------------------------------------------"<<endl;
            //cout<<"       Display elements of the linked list: "<<endl;
            display();
            cout<<" -----------------------------------------------------------------------"<<endl;
            break;

        case 9:
            {
            cout<<" -----------------------------------------------------------------------"<<endl;
            struct node *ptr=head;
            ppcount = ccount(ptr);
            cout<<"         Number of nodes in the Linked List : "<<ppcount<<"\n";
            cout<<" -----------------------------------------------------------------------"<<endl;
            }
            break;

        case 10:
            {
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Exiting..."<<endl;
            cout<<" -----------------------------------------------------------------------"<<endl;
            exit(1);
            }
            break;

        default:
            cout<<" -----------------------------------------------------------------------"<<endl;
            cout<<"         Wrong choice ( Enter from 1 and 9 ) "<<endl;
            cout<<" -----------------------------------------------------------------------"<<endl;
        }
    }


return 0;
}

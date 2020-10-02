/* their are n people in a circle and kth person gets executed each time this goes on
until their is one survivor remaining*/
#include<bits/stdc++.h>
using namespace std;

struct cnode{
int data;
struct cnode *next;
};

typedef struct cnode *clptr;
//insert nodes in a circular linked list
void insert(clptr hd,clptr &l,int k)
{
	clptr t=new(cnode);
	t->data=k;
	t->next=NULL;
	clptr t1=hd;
	if(hd->next==NULL)
	{hd->next=t;
	l=t;
	l->next=l;
	}
	else
	{   clptr t1=hd->next;
		while(t1->next!=hd->next)
		{t1=t1->next;}
		t1->next=t;
        t->next=hd->next;
	}
}
//delete nodes
void del(clptr hd,clptr t)
{
    if(hd->next->next==hd->next)
    {
        hd->next=NULL;
        return ;
    }

    if(hd->next==t)
    {
        clptr t1=hd->next;
        while(t1->next!=hd->next)
        {
            t1=t1->next;
        }
        t1->next=hd->next->next;
        hd->next=hd->next->next;
        return ;
    }
    else{
        clptr t1=hd->next;
        while(t1->next!=t)
        {
            t1=t1->next;
        }
        t1->next=t1->next->next;
    }
}

int survive(clptr hd,int k)
{
    clptr t=hd->next;
    int i=1;
    while(t->next!=t)
    {
        t=t->next;
        i++;
        if(i==k)
        {
            cout<<t->data<<" ";
            clptr t1=t->next;

            del(hd,t);
            hd->next=t1;

            survive(hd,k);
        }
    }

    return t->data;
}
int main()
{
//hd is the head node for circular linked list
 clptr hd=new(cnode);
 hd->next=NULL;
 clptr l=NULL;
 int n,a;
 cout<<"enter no. of people "<<endl;
 cin>>n;
 while(n--)
 {
    cin>>a;
    insert(hd,l,a);
 }
 cout<<"enter the the value k i.e the person getting executed"<<endl;
 int k;
 cin>>k;
 //survive function to find the lone survivor
 cout<<"people executed after each round"<<endl;
 int ans=survive(hd,k);
 cout<<endl;
 cout<<"the lone survivor"<<endl;
 cout<<ans<<endl;

}

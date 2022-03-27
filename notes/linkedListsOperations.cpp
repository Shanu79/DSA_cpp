#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

int count(struct Node *p)
{
    int counter=0;
    
    while(p!=NULL)
    {
        /* code */
        counter++;
        p=p->next;
    }
    return counter;
}

void display(struct Node *p)
{
    while (p!=NULL)
    {
        /* code */
        printf("%d ",p->data);
        p=p->next;
    }
    
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index<0 || index<count(p)) //index validity checker
    {
        /* code */
        return;
    }
    
    t=new Node;
    t->data=x;

    if (index==0) //if the to be inserted node is first node
    {
        /* code */
        t->next=first; //t next points to the first node
        first=t; //making t as the first node
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            /* code */
            p=p->next; //moving p to the position of the index 
        }
        t->next=p->next; //making next t point to next p
        p->next=t; //making next p point to t
    }
    
}

void lastInsert(struct Node *p,int x)
{
    struct Node *t,*last=p;

    t=new Node;
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    {
        first=t;
        last=t;
    }
    else
    {
        while (last->next!=NULL)
        {
            last=last->next;
        }
        last->next=t;
        last=t;
    }
}

int LLmax(struct Node *p)
{
    int max= INT_LEAST16_MIN;

    while (p)
    {
        if (p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
return max;
}

int LLmin(struct Node *p)
{
    int min= INT_LEAST16_MAX;

    while (p)
    {
        if (p->data<min)
        {
            min=p->data;
        }
        p=p->next;
    }
return min;
}

bool lsearch(struct Node *p,int key)
{
    while (p)
    {
        /* code */
        if (key==p->data)
        {
            /* code */
            return true;
        }
        p=p->next;
    }
    return false;
    
}

Node *Rsearch(struct Node *p,int key)
{
    if (p==NULL)
    {
        return NULL;
    }
    if (p->data==key)
    {
        /* code */
        return p;
    }
    else
        return Rsearch(p->next,key);
}

int LLdelete(struct Node *p,int pos)
{
    struct Node *t=p;
    struct Node *q=NULL;

    if(pos<0 || pos>count(first))
    {
        return -1;
    }

    if (pos==1)
    {
        /* code */
        q=first;
        first=first->next;
        delete q;
    }
    
    for (int i = 0; i < pos-1; i++)
    {
        q=t;
        t=t->next;
    }

    q->next=t->next;
    delete t;
    return t->data;
}

bool isSorted(struct Node *p)
{
    int x=INT16_MIN;
    
    while (p)
    {
        /* code */
        if (x>p->data)
        {
            /* code */
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}

//remove duplicates


int main()
{
    insert(first,0,10);
    insert(first,1,0);
    insert(first,2,2);
    insert(first,3,3);

    lastInsert(first,111);
    lastInsert(first,6);
    cout<<lsearch(first,111)<<endl;
    //cout<<Rsearch(first,111)<<endl;
    cout<<LLmax(first)<<endl;
    cout<<LLmin(first)<<endl;

    cout<<LLdelete(first,1)<<endl;
    display(first);

    cout<<endl;
    cout<<isSorted(first);




    return 0;
}
#include<iostream>
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

void lastInsert(int x)
{
    struct Node *t;
    
    t=new Node;
    t->data=x;

    
}

int main()
{
    insert(first,0,10);
    insert(first,1,1);
    insert(first,2,2);
    insert(first,3,3);

    display(first);
    return 0;
}
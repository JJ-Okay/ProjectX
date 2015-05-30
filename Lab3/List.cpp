#include <iostream>
using namespace std;
struct st
{
    int current;
    st* next;
    st* prev;
};
st* last_el(st*a )
{
    while(a->next)
        a=a->next;
    return a;
}
void del (st* a)
{
    a->current=0;
    
    if (a->prev)
        a->prev->next=a->next;
    
    if (a->next)
        a->next->prev=a->prev;
    
    a->prev=NULL;
    a->next=NULL;
    
}
void add (st*a, int data)
{
    a=last_el(a);
    st* b=new st;
    b->current=data;
    b->next=NULL;
    b->prev=a;
    a->next=b;
};

void print (st*a)
{
    while(a->prev)
        a=a->prev;
    do 
    {
        cout << a->current <<endl;
        a=a->next;
    }
    while(a->next);
}

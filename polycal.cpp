#include<iostream>
#include<stdlib.h>

const int ok=1;
const int error=0;
const int overflow=-1;

using namespace std;

typedef bool status;
typedef struct Node
{
        int power_time;
        int coefficient;
        struct Node *next;
}power_node;

int length(power_node &L);
void poly_calculate(power_node &L,int *a,int n);
void init_list(power_node &L);
status insert(power_node &L,int a);      //add or insert depend on existence of power    a means power num

int main()
{
        int a;//store the type 
        cout<<"Input the type of the items"<<endl;
        cin>>a;
        int type[a];    //store the type
        int **list=new int * [a];
        int i,j;
        int low,high;
        int n;  
        for(i=0;i<a;i++)
        {
                cout<<"Input the "<<i+1<<"th type"<<endl;
                cin>>type[i];
                cout<<"Input the range\n"<<"low\thigh"<<endl;
                cin>>low;
                cin>>high;
                n=(high-low)/type[i]+1;
                list[i]=new int[n];
                for(j=0;j<n;j++)
                {
                        list[i][j]=low+j*type[i];
                }
        }
}


int length(power_node &L)
{
        int i;
        power_node *p=&L;
        for(i=0;p->next!=NULL;i++)
                p=p->next;
        return i;
}

void poly_calculate(power_node &L,int *a,int n)
{
        int len=length(L);
        int b[len];
        int i,j;
        power_node *p=L.next;
        for(i=0;i<len;i++)
        {
                b[i]=p->power_time;
        }
        for(i=0;i<len;i++)
        {
                for(j=0;j<n;j++)
                {
                        insert(L,b[i]+a[j]);
                }
        }
}

status insert(power_node &L,int a)       //add or insert depend on existence of power    a means power num
{
        power_node *p1,*p2;
        p1=&L;
        p2=p1->next;
        while(p2)
        {
                if(p2->power_time<a)
                {
                        p1=p2;
                        p2=p2->next;
                }
                else if(p2->power_time==a)
                {
                        p2->coefficient++;
                        return ok;
                }
                else if(p2->power_time>a)
                {
                        power_node *new_node=(power_node *)malloc(sizeof(power_node));
                        new_node->power_time=a;
                        new_node->coefficient=1;
                        p1->next=new_node;
                        new_node->next=p2;
                        return ok;
                }
        }
        if(p2)
        {
                power_node *new_node=(power_node *)malloc(sizeof(power_node));
                new_node->power_time=a;
                new_node->coefficient=1;
                p1->next=new_node;
                new_node->next=p2;
                return ok;
        }
        return error;
}

//===========================================================================================
//++++++++++++++++++++++++++++++++++OOP Queue DataStructure++++++++++++++++++++++++++++++++
//-------------------------------------------------------------------------------------------

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int  data;
    struct node *next;

}NODE,*PNODE,**PPNODE;

class Queue
{
    private:
        PNODE first;
        int Count;
    public:
        Queue();
        void enqueue(int No);
        int dequeue();
        void Display();
        int CountNode();
};

Queue::Queue()
{
    first = NULL;
    Count = 0;
}
void Queue::enqueue(int No) //Insert Last
{
    PNODE newn = NULL;
    PNODE Temp = first;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->next = NULL;
    }
}

int Queue::dequeue()
{
    int Value = 0;
    PNODE Temp = first;

    if(first == NULL)
    {
        cout<<"Queue is already empty\n";
        return -1;
    }
    else if(first->next == NULL)
    {
        Value = first->data;
        delete(first);
        first = NULL;
    }
    else
    {
        Value = first->data;
        first = first->next;
        delete(Temp);
    }
    return Value;
}

void Queue::Display()
{
    PNODE Temp = first;
    if(first == NULL)
    {
        cout<<" Queue is Empty...\n";
        return;
    }
    else
    {
        cout<<"Exit<---";
        while(Temp != NULL)
        {
            cout<<"| "<<Temp->data<<" |<--";
            Temp = Temp->next;
        }cout<<"Entry\n";
    }
}
int main()
{
    Queue qobj;
    int iRet = 0;

    qobj.enqueue(10);
    qobj.enqueue(20);
    qobj.enqueue(30);
    qobj.enqueue(40);
    qobj.Display();
    iRet = qobj.dequeue();
    cout<<"Dequeued value is : "<<iRet<<"\n";
    qobj.Display();

    return 0;
}

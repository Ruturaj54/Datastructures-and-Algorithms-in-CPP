
//********************************************************************************
//+++++++++++++++++++++++OOP Based Stack DataStructure++++++++++++++++++++++++++++
//================================================================================

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Stack
{
    private:
        PNODE first;
        int Count;
    public:
        Stack();
        void Push(int No);
        int Pop();
        void Display();
        int CountNode();
};

Stack::Stack()
{
    first = NULL;
    Count = 0;
}
void Stack::Push(int No)
{
    PNODE newn = NULL;
    PNODE Temp = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

}

int Stack::Pop()
{
    int Val = 0;
    PNODE Temp = first;
    if(first == NULL)
    {
        cout<<"Stack is Empty..\n";
        return -1;
    }
    else
    {
        Val = first->data;
        first = first->next;
        delete(Temp);

    }
    return Val;
}

void Stack::Display()
{
    PNODE Temp = first;

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->data<<" |\n";
        Temp = Temp->next;
    }cout<<"  NULL\n";
}

int Stack::CountNode()
{
    PNODE Temp = first;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp->next;
    }
    return iCnt;
}

int main()
{
    Stack sobj;
    int iRet = 0;
    sobj.Push(100);
    sobj.Push(200);
    sobj.Push(300);
    sobj.Push(400);
    sobj.Display();


    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    iRet = sobj.Pop();
    cout<<"Popped Elements is : "<<iRet<<"\n";

    iRet = sobj.CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    sobj.Display();




    return 0;
}
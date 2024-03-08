

// ==================================================================================
// ********************Doubly Circular Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;


class DoublyCircular
{
    private:
        PNODE first;
        PNODE Tail;
        int Count;
    public:
        DoublyCircular();
        void InsertFirst(int No);
        void InsertLast(int No);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int CountNode();
        void InsertAtPos(int No,int iPos);
        void DeleteAtPos(int iPos);
};

DoublyCircular::DoublyCircular()
{
    first = NULL;
    Tail = NULL;
    Count = 0;

}

void DoublyCircular::InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        newn->next = Tail;
        Tail->prev = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Tail->next = first;
    first->prev = Tail;
}

void DoublyCircular::InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

     if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Tail->next = first;
    first->prev = Tail;
}

void DoublyCircular::DeleteFirst()
{
    PNODE Temp = first;

    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first == Tail)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);
         first->prev = Tail;
         Tail->next = first;
    }
    
}

void DoublyCircular::DeleteLast()
{
     if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first == Tail)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete(Tail->next);
        Tail->next = first;
        first->prev = Tail;
    }

}

void DoublyCircular::Display()
{
    if(first != NULL && Tail != NULL)
    {
    PNODE Temp = first;
    cout<<"Address of Tail<==>";
    do
    {
        cout<<"| "<<Temp->data<<" |<==>";
        Temp = Temp->next;

    }while(Temp != Tail->next);
    cout<<"Address of First\n";
    }
}

int DoublyCircular::CountNode()
{
    PNODE Temp = first;
    Count = 0;
    do
    {
        Count++;
        Temp = Temp->next;

    }while(Temp != Tail->next);
    return Count;
}

void DoublyCircular::InsertAtPos(int No,int iPos)
{
    PNODE Temp = first;
    int Size = 0;
    Size = CountNode();
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid Position..\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size)
    {
        InsertLast(No);
    }
    else
    {
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next->prev = newn;
        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next = newn;
        
    }
    Tail->next = first;
    first->prev = Tail;
}

void DoublyCircular::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    PNODE Temp = first;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid position...\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;
    }
    Tail->next = first;
    first->prev = Tail;
}

int main()
{
    DoublyCircular dobj;
    int iRet = 0;

    dobj.InsertFirst(11);
    dobj.InsertFirst(21);
    dobj.InsertFirst(51);
    dobj.InsertFirst(101);
    dobj.InsertLast(11);
    dobj.InsertLast(21);
    dobj.InsertLast(51);
    dobj.InsertLast(101);

    dobj.Display();

    iRet = dobj.CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPos(1111,3);

    dobj.Display();

    iRet = dobj.CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(3);

    dobj.Display();

    iRet = dobj.CountNode();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    

    return 0;
}
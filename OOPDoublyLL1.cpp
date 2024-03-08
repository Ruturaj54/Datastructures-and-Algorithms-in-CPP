

// ==================================================================================
// ********************Doubly Linear Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}NODE,*PNODE,**PPNODE;

class DoublyLL
{
    private:
        PNODE first;
        int Count;
    public:
        DoublyLL();
        void InsertFirst(int No);
        void InsertLast(int No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int No,int iPos);
        void DeleteAtPos(int iPos);

};

DoublyLL::DoublyLL()
{
    first = NULL;
    Count = 0;
}

void DoublyLL::InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->prev = NULL;
        newn->next = first;
        first->prev = newn;
        first = newn;

    }
}

void DoublyLL::InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    PNODE Temp = first;

    if(first == NULL)
    {
        first = newn;
    }
    else if(first->next == NULL)
    {
        first->next = newn;
        newn->prev = first;
        newn->next = NULL;
        first->prev = NULL;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
        newn->next = NULL;
    }
}

void DoublyLL::Display()
{
    PNODE Temp = first;

    cout<<"NULL<==>";
    while (Temp != NULL)
    {
        cout<<"| "<<Temp->data<<" |<==>";
        Temp = Temp->next;
    }cout<<"NULL\n";
    
}

int DoublyLL::CountNode()
{
    PNODE Temp = first;
    Count = 0;
    while(Temp != NULL)
    {
        Count++;
        Temp = Temp->next;
        
    }
    return Count;

}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"The Linked List is already Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);
        first->prev = NULL;
    }
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"The Linked List is already Empty...\n";
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        PNODE Temp = first;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete(Temp->next);
        Temp->next = NULL;
    }

}

void DoublyLL::InsertAtPos(int No,int iPos)
{
    int Size = 0;
    Size = CountNode();
    PNODE Temp = first;
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid position..\n";
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
        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
}

void DoublyLL::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    PNODE Temp = NULL;
    Temp = first;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid position..\n";
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
        for(int i = 1;i < iPos -1;i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;
    }
}

int main()
{
    DoublyLL dobj;
    int iRet = 0;
    dobj.InsertFirst(11);
    dobj.InsertFirst(21);
    dobj.InsertFirst(51);
    dobj.InsertFirst(101);
    dobj.InsertLast(2000);

    dobj.Display();

    // dobj.DeleteLast();

    // dobj.Display();

    // dobj.DeleteFirst();

    // dobj.Display();

    

    // dobj.InsertAtPos(711,2);
    

    // dobj.Display();

    // dobj.DeleteAtPos(2);

    //  dobj.Display();
    iRet = dobj.CountNode();
    cout<<"Number of Node are : "<<iRet<<"\n";


    return 0;
}
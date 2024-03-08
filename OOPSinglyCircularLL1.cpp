

// ==================================================================================
// ********************SINGLY Circular Linear Linked List****************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

class SinglyCircular
{
    private:
        PNODE first;
        PNODE Tail;
        int Count;
    public:
        SinglyCircular();
        void InsertFirst(int No);
        void InsertLast(int No);
        int CountNode();
        void Display();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int No,int iPos);
        void DeleteAtPos(int iPos);
};

SinglyCircular::SinglyCircular()
{
    first = NULL;
    Tail = NULL;
    Count = 0;
}
void SinglyCircular::InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        Tail->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        Tail->next = first;
        
    }
}

void SinglyCircular::InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL && Tail == NULL)
    {
        first = newn;
        Tail = newn;
        Tail->next = first;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
        newn->next = first;
    }
}

void SinglyCircular::DeleteFirst()
{
    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first->next == first)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        first = first->next;
        delete(Tail->next);
        Tail->next = first;
    }

}

void SinglyCircular::DeleteLast()
{
    if(first == NULL && Tail == NULL)
    {
        cout<<"Linked List is Empty...\n";
        return;
    }
    else if(first->next == first)
    {
        delete(first);
        first = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE Temp = first;
        while(Temp->next != Tail)
        {
            Temp = Temp->next;
        }
        delete(Tail);
        Tail = Temp;
        Tail->next = first;

    }

}


void SinglyCircular::Display()
{
    if(first != NULL && Tail != NULL)
    {
        do
        {
            cout<<"| "<<first->data<<" |-->";
            first = first->next;
        } while(first != Tail->next);
        
        cout<<"Address of First Node\n";
    }
    else
    {
        cout<<"Linked List is Empty \n";
        return;
    }
}

int SinglyCircular::CountNode()
{
    PNODE Temp = first;
    Count = 0;
    do
    {
        Temp=Temp->next;
        Count++;
    }while(Temp != first);
    return Count;
}

void SinglyCircular::InsertAtPos(int No ,int iPos)
{
    int Size = 0;
    Size = CountNode();

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
        PNODE Temp = first;
        PNODE Tempx = NULL;
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = No;
        newn->next = NULL;

        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next;
        Temp->next = newn;
        newn->next = Tempx;
        
    }
}

void SinglyCircular::DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid Position..\n";
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
        PNODE Temp = first;
        PNODE Tempx = NULL;
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next->next;
        delete(Temp->next);
        Temp->next = Tempx;
        Tail->next = first;

    }
}


int main()
{
    SinglyCircular sobj;
    int iRet = 0;
    sobj.InsertFirst(11);
    sobj.InsertFirst(21);
    sobj.InsertLast(51);
    sobj.InsertLast(101);
    sobj.InsertAtPos(111,3);
    sobj.Display();
    sobj.DeleteAtPos(3);
    //sobj.Display();
    //sobj.DeleteFirst();
    //sobj.DeleteLast();
    sobj.Display();

    iRet = sobj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    return 0;
}
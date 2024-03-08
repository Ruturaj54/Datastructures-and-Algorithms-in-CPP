

// ========================================================================
// ********************SINGLY Linear Linked List***************************
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

class SinglyLL
{
    private:
        PNODE first;
        int Count;
    public:
        SinglyLL();
        void InsertFirst(int No);
        void InsertLast(int No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int No,int iPos);
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    first = NULL;
    Count = 0;
}
void SinglyLL::InsertFirst(int No)
{
    PNODE newn = NULL;
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

void SinglyLL::InsertLast(int No)
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
    else if(first->next == NULL)
    {
        first->next = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void SinglyLL::Display()
{
    PNODE Temp = first;

    cout<<"Contents of Linked List are : \n";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|-->";
        Temp = Temp->next;
    }cout<<"NULL\n";
}

int SinglyLL::CountNode()
{
    PNODE Temp = first;
    Count = 0;

    while(Temp != NULL)
    {
        Temp = Temp->next;
        Count++;
    }
    return Count;
    
}

void SinglyLL::DeleteFirst()
{
    if(first == NULL)
    {
        cout<<"The Linked List is Empty...\n";
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
        first = first->next;
        delete(Temp);
    }
}
void SinglyLL::DeleteLast()
{
    if(first == NULL)
    {
        cout<<"The Linked List is Empty...\n";
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

void SinglyLL::InsertAtPos(int No,int iPos)
{
    int Size = 0;
    Size = CountNode();
    if(iPos < 1 || iPos > Size + 1)
    {
        cout<<"Invalid Position...\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size)
    {
        InsertLast(No);
    }
    else
    {
        PNODE newn = NULL;
        PNODE Tempx = NULL;
        newn = new NODE;
        newn->data = No;
        newn->next = NULL;
        PNODE Temp = first;

        for(int i = 1;i < iPos - 1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next;
        Temp->next = newn;
        newn->next = Tempx;

    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    int Size = 0;
    Size = CountNode();
    PNODE Temp = first;
    PNODE Tempx = NULL;

    if(iPos < 1 || iPos > Size)
    {
        cout<<"Invalid Position ...\n";
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
        for(int i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Tempx = Temp->next->next;
        delete(Temp->next);
        Temp->next = Tempx;
    }
}

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(111);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(111);
    obj.InsertLast(51);
    obj.InsertLast(21);
    obj.InsertLast(11);

    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(511,3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    
    return 0;
}
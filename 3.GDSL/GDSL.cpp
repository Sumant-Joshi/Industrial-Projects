#include<iostream>
using namespace std;

#pragma pack(1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                        //
//                                          STRUCTURE DECLRATIONS                                         //
//                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// SINGLY SELF REFRENTIAL STRUCTURE DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct snode
{
    T data;
    struct snode *next;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// DOUBLY SELF REFRENTIAL STRUCTURE DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>   
struct dnode
{
    T data;
    struct dnode <T>*next;
    struct dnode <T>*prev;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                        //
//                                           CLASS DECLARATIONS                                           //
//                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// SINGLY LINEAR LINKED LIST CLASS DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    public:
        // Characteristics
        struct snode <T>* First;
        int iCount;

        // Behaviours
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// SINGLY CIRCULAR LINKED LIST CLASS DECLERATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCL
{
    public:
        struct snode <T>* First;
        struct snode <T>* Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// DOUBLY LINEAR LINKED LIST CLASS DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    public :
        struct dnode <T>* First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
//  DOUBLY CIRCULAR LINKED LIST CLASS DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCL
{
    public:
        struct dnode <T>* First;
        struct dnode <T>* Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// STACK CLASS DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
        struct snode <T>*First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T no);      // Insert
        int Pop();              // Delete
        void Display();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// QUEUE CLASS DECLARATION
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class Queue
{
    public:
        struct snode <T>*First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T no);      // Insert
        int DeQueue();              // Delete
        void Display();
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                        //
//                                           METHOD DEFINITIONS                                           //
//                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// SINGLY LINEAR LINKED LIST METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL <T>:: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL <T>:: InsertFirst(T no)
{
    // Step1 : Allocate memory for snode
    struct snode<T>* newn = new struct snode<T>;

    // Step2 : Initialise snode
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one snode
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}


template<class T>
void SinglyLL <T>:: InsertLast(T no)
{
    // Step1 : Allocate memory for snode
    struct snode<T>* newn = new struct snode<T>;

    // Step2 : Initialise snode
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL contains atleast one snode
    {
        struct snode<T>* temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template<class T>
void SinglyLL <T>:: InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct snode<T>* newn = new struct snode<T>;

        newn->data = no;
        newn->next = NULL;

        struct snode<T>* temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL <T>:: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct snode<T>*  temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

template<class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct snode<T>* temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template<class T>
void SinglyLL <T>:: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct snode<T>* temp1 = First;

        for (int iCnt = 1 ; iCnt < ipos-1 ; iCnt++)
        {
            temp1 = temp1->next;
        }
        struct snode<T>* temp2 = temp2->next;
        delete temp2;

        iCount--;
    }
}

template<class T>
void SinglyLL <T>:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct snode<T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// SINGLY CIRCULAR LINKED LIST METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                          
template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct snode<T> * newn = new struct snode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one snode
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct snode <T>* newn = new struct snode<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one snode
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::Display()
{
    struct snode <T>* temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    struct snode <T>* temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    struct snode <T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single snode in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 snode
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct snode<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single snode in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 snode
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct snode <T>* newn = NULL;
    struct snode <T>* temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct snode <T>* newn = new struct snode<T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct snode <T>* temp1 = First;
    struct snode <T>* temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// DOUBLY LINEAR LINKED LIST METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLL <T>:: DoublyLL()
{
    First = NULL;
}

template<class T>
void DoublyLL <T>:: InsertFirst( T no)
{
    struct dnode <T>* newn = new struct dnode <T> ;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}

template<class T>
void DoublyLL <T>:: InsertLast( T no)
{
    struct dnode <T>* newn = new struct dnode <T>;
    struct dnode <T>* temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

template<class T>
void DoublyLL <T>:: Display()
{
    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";
    struct dnode <T>* temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

template<class T>
int DoublyLL <T>:: Count()
{
    int iCnt = 0;
    struct dnode <T>* temp = First;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

template<class T>
void DoublyLL <T>:: DeleteFirst()
{
    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 dnode
    {
        delete(First);
        First = NULL;
    }
    else    // LL contains more than 1 dnode
    {
        First = (First) -> next;
        delete((First)->prev);               // X
        (First)->prev = NULL;              // X
    }
}

template<class T>
void DoublyLL <T>:: DeleteLast()
{
    struct dnode <T>* temp = First;

    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 dnode
    {
        delete(First);
        First = NULL;
    }
    else    // LL contains more than 1 dnode
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
    }
}

template<class T>
void DoublyLL <T>:: InsertAtPos( T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct dnode <T>* newn = NULL;
    struct dnode <T>* temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct dnode<T> ;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

template<class T>
void DoublyLL <T>:: DeleteAtPos(int ipos)
{
    struct dnode <T>* temp1 = NULL;
    struct dnode <T>* temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      // X
        delete(temp2);
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// DOUBLY CIRCULAR LINKED LIST METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCL <T>:: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}

template<class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    struct dnode <T>* newn = new struct dnode<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL <T>:: InsertLast(T no)
{
    struct dnode <T>* newn = new struct dnode<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL <T>:: Display()
{
    struct dnode <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template<class T>
int DoublyCL <T>:: Count()
{
    int iCnt = 0;
    struct dnode <T>* temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template<class T>
void DoublyCL <T>:: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single dnode
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one dnode
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single dnode
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one dnode
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL <T>:: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
    struct dnode <T>* newn = NULL;
    struct dnode <T>* temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct dnode <T>* temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// STACK METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Stack <T>:: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void Stack <T>:: Push(T no)  // InsertFirst
{
    struct snode <T>* newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    
    iCount++;

    cout<<no<<" gets pushed in the stack succesfully"<<"\n";
}

template<class T>
int Stack <T>:: Pop()          // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty."<<"\n";
        return -1;
    }
    else 
    {
        int value = First -> data;
        struct snode <T>*temp = First;

        First = First ->next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void Stack <T>:: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else 
    {
        cout<<"Elements of stack are : "<<"\n";

        struct snode <T>*temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
// QUEUE METHOD DEFINITIONS
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue <T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

template<class T>
bool Queue <T>:: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void Queue <T>:: EnQueue(T no)  // InsertLast
{
    struct snode <T>*newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct snode <T>*temp = First;

        while(temp->next != NULL)
        {
           temp = temp ->next; 
        }

        temp->next = newn;
    }
    
    iCount++;

    cout<<no<<" gets pushed in the Queue succesfully"<<"\n";
}

template<class T>
int Queue <T>:: DeQueue()          // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Queue is empty."<<"\n";
        return -1;
    }
    else 
    {
        int value = First -> data;
        struct snode <T>*temp = First;

        First = First ->next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void Queue <T>:: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty."<<"\n";
    }
    else 
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct snode <T>*temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp -> next;
        }
        cout<<" NULL"<<"\n";
    }
}



int main()
{
    return 0;
}
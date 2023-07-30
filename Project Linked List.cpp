//Project 1 Linked List

/* Project Name : Linked List
Description : Project that takes input from user and perform operations on different types of Linked List
Author : Akanksha Vinay Deo
Date : 4/07/23
*/

#include<iostream>
using namespace std;

typedef class Node
{
public:
    int data;
    struct Node *next;
    struct Node *prev;

    Node()                   //Default Constructor
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node (int value)               //Parameterized Constructor
    {
        data = value;
        next = NULL;
        prev = NULL;
    }

}NODE, *PNODE;

class LinkedList                 //Abstraction   //Runtime Polymorphism  //base class
{
public:
    PNODE First;
    int iCount;

    LinkedList()
    {
        First = NULL;
        iCount = 0;
    }

    virtual void InsertFirst(int ino) = 0;            //Abstract methods : same for all classes
    virtual void InsertLast(int ino) = 0;
    virtual void InsertAtPos(int ino, int ipos) = 0;

    virtual void DeleteFirst() = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteAtPos(int ipos) = 0;

    void Display()
    {
        PNODE temp = First;

        cout<<"Elements of Linked List are : \n";
        for (int icnt = 1; icnt <= iCount; icnt++)
        {
            cout<< " |"<<temp->data<<"| -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
    }

    int Count()
    {
        return iCount;
    }

};

///////////////////////////////////////////////////////////////////
//                  SINGLY LINEAR LINKED LIST CODE               //
///////////////////////////////////////////////////////////////////

class SinglyLL : public LinkedList                         //child class
{

public:
    SinglyLL();
    ~SinglyLL();

    void InsertFirst(int ino);
    void InsertLast(int ino);
    void InsertAtPos(int ino, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

};

SinglyLL :: SinglyLL()
{

}

SinglyLL :: ~SinglyLL()
{
    PNODE temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}


void SinglyLL :: InsertFirst(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL)   //LL is empty
    {
        First = newn;
    }
    else               //LL contains at least one node
    {
        newn -> next = First;
        First = newn;
    }

    iCount++;
}

void SinglyLL :: InsertLast(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL)   //LL is empty
    {
        First = newn;
    }
    else               //LL contains at least one node
    {
        PNODE temp = First;

        while (temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;
    }

    iCount++;

}

void SinglyLL :: InsertAtPos(int ino, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(ino);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(ino);
    }
    else
    {
        PNODE temp = First;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        PNODE newn = new NODE (ino);

        newn->next = temp->next;
        temp -> next = newn;

        iCount++;
    }

}

void SinglyLL :: DeleteFirst()
{
    if (First == NULL)     //Empty LL
    {
        return;
    }
    else if (First -> next == NULL)         //1 node in LL
    {
        delete First;
        First = NULL;
    }
    else       //More than one node in LL
    {
        PNODE temp = First;
        First = First-> next;
        delete temp;
    }

    iCount--;
}

void SinglyLL :: DeleteLast()
{
    if (First == NULL)     //Empty LL
    {
        return;
    }
    else if (First -> next == NULL)         //1 node in LL
    {
        delete First;
        First = NULL;
    }
    else       //More than one node in LL
    {
        PNODE temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;     //not applicable for if part
}



void SinglyLL :: DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst( );
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp -> next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////
//                SINGLY CIRCULAR LINKED LIST CODE               //
///////////////////////////////////////////////////////////////////

class SinglyCL : public LinkedList
{
private:
    PNODE Last;

public:
    SinglyCL();
    ~SinglyCL();

    void InsertFirst(int ino);
    void InsertLast(int ino);
    void InsertAtPos(int ino, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

};

SinglyCL :: SinglyCL()
{
    Last = NULL;
}

SinglyCL :: ~SinglyCL()
{
    PNODE temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }
}

void SinglyCL :: InsertFirst(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last -> next = First;
    iCount++;
}

void SinglyCL :: InsertLast(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last -> next = newn;
    iCount++;

}

void SinglyCL :: InsertAtPos(int ino, int ipos)
{
    if ((ipos < 0) || (ipos > iCount + 1))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        InsertFirst(ino);
    }
    else if (ipos == iCount +1)
    {
        InsertLast(ino);
    }
    else
    {
        PNODE temp = First;
        PNODE newn = new Node (ino);

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
    iCount++;
}

void SinglyCL :: DeleteFirst()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First -> next;
        delete(temp);
    }
    Last -> next = First;
    iCount--;
}

void SinglyCL :: DeleteLast()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        PNODE temp = First;

        while (temp -> next != Last)
        {
            temp =  temp -> next;
        }

        delete(Last);
        Last = temp;
        Last -> next = First;

    }
    Last -> next = First;
    iCount--;

}

void SinglyCL :: DeleteAtPos(int ipos)
{
    if ((ipos < 0) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount +1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }

        tempX = temp -> next;

        temp -> next = temp -> next -> next;
        delete(tempX);
    }
    iCount--;

}

///////////////////////////////////////////////////////////////////
//                DOUBLY LINEAR LINKED LIST CODE                //
///////////////////////////////////////////////////////////////////

class DoublyLL : public LinkedList
{

public:
    ~DoublyLL();

    void InsertFirst(int ino);
    void InsertLast(int ino);
    void InsertAtPos(int ino, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

};

DoublyLL :: ~DoublyLL()
{
    PNODE temp = First;

    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First -> next;
        delete temp;
    }

}

void DoublyLL :: InsertFirst(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
    iCount++;
}

void DoublyLL :: InsertLast(int ino)
{
    PNODE newn = new NODE(ino);

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;

}

void DoublyLL :: InsertAtPos(int ino, int ipos)
{
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(ino);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(ino);
    }
    else
    {
        PNODE newn = new NODE (ino);
        PNODE temp = First;

        for (int icnt = 1; icnt < ipos - 1 ; icnt++)
        {
              temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;
    }
    iCount++;
}

void DoublyLL :: DeleteFirst()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        PNODE temp = First;
        First = First -> next;
        delete temp;
    }
    iCount--;
}

void DoublyLL :: DeleteLast()
{
    if (iCount == 0)
    {
        cout<<"Nothing in Linked List\n";
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        PNODE temp = First;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp-> next);
        temp -> next = NULL;
    }
    iCount--;
}

void DoublyLL :: DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;

        for (int icnt = 1; icnt < ipos - 1 ; icnt++)
        {
              temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete(temp->next-> prev);
        temp -> next -> prev = temp;

    }
    iCount--;

}

///////////////////////////////////////////////////////////////////
//                DOUBLY LINEAR LINKED LIST CODE                //
///////////////////////////////////////////////////////////////////
class DoublyCL : public LinkedList         //Inheritance
{
private:
    PNODE Last;

public:
    DoublyCL();
    ~DoublyCL();

    void InsertFirst(int ino);
    void InsertLast(int ino);
    void InsertAtPos(int ino, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

};

DoublyCL :: DoublyCL()
{
    Last = NULL;
}

DoublyCL :: ~DoublyCL()
{

}

void DoublyCL :: InsertFirst(int ino)
{
    PNODE newn = new NODE (ino);           //goes to typedef class

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

void DoublyCL :: InsertLast(int ino)
{
    PNODE newn = new NODE (ino);           //goes to typedef class

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = Last -> next;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;

}

void DoublyCL ::InsertAtPos(int ino, int ipos)
{
    if ((ipos < 0) || (ipos > iCount + 1))
    {
        cout<<"INvalid position\n";
    }

    if (ipos == 1)
    {
        InsertFirst(ino);
    }
    else if (ipos == iCount +1)
    {
        InsertLast(ino);
    }
    else
    {
        PNODE temp = First;

        for (int icnt = 1; icnt < ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        PNODE newn = new Node (ino);

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

void DoublyCL :: DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First-> next;
        delete First -> prev;

        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;
}

void DoublyCL :: DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last-> prev;
        delete Last -> next;

        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;

}

void DoublyCL :: DeleteAtPos(int ipos)
{
    if ((ipos < 0) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;

        for (int icnt = 1; icnt <= ipos - 1; icnt++)
        {
            temp = temp->next;
        }
        temp -> next = temp->next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
    }
    iCount--;
}




int main()
{
    SinglyLL obj1;
    SinglyCL obj2;
    DoublyLL obj3;
    DoublyCL obj4;
    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;

    cout<<"Akanksha's LinkedList Application\n";

    while (1)
    {
        cout<<"________________________________\n";
        cout<<"Please choose type of Linked List to perform operations : \n";
        cout<<"1. SINGLY LINEAR LINKED LIST \n\n";
        cout<<"2. SINGLY CIRCULAR LINKED LIST \n\n";
        cout<<"3. DOUBLY LINEAR LINKED LIST \n\n";
        cout<<"4. DOUBLY CIRCULAR LINKED LIST \n\n";

        cin>>iChoice;
        cout<<"_____________________________________\n";

        switch(iChoice)
        {
        case 1:
            while (1)     //unconditional loop
    {
        cout<<"_________________________________\n";
        cout<<" Welcome to Singly Linear Linked List . \n Please enter your choice : \n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node from first position\n";
        cout<<"5 : Delete node from last position\n";
        cout<<"6 : Delete node from given position\n";
        cout<<"7 : Display Linked List\n";
        cout<<"8 : Counter number of nodes from Linked List\n";
        cout<<"9 : Terminate the application\n";

        cin>>iChoice;

        cout<<"_________________________________\n";

        switch(iChoice)
        {
        case 1 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj1.InsertFirst(iValue);
            break;
        case 2 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj1.InsertLast(iValue);
            break;
        case 3 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            cout<<"Enter the position you want to insert : \n";
            cin>>iPosition;
            obj1.InsertAtPos(iValue, iPosition);
            break;
        case 4 :
            cout<<"Deleting First element : \n";
            obj1.DeleteFirst();
            break;
        case 5 :
            cout<<"Deleting Last element : \n";
            obj1.DeleteLast();
            break;
        case 6 :
            cout<<"Enter the position you want to delete : \n";
            cin>>iPosition;
            obj1.DeleteAtPos(iPosition);
            break;
        case 7 :
            obj1.Display();
            break;
        case 8 :
            cout<<"Number of elements are : "<<obj1.Count() <<"\n";
            break;
        case 9 :
            cout<<"Thank you for using the application\n";
            return 0;

        default :
            cout<<"Invalid choice\n";
            break;
        }

    }
        case 2:
            while (1)     //unconditional loop
    {
        cout<<"_________________________________\n";
        cout<<" Welcome to Singly Circular Linked List . \nPlease enter your choice : \n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node from first position\n";
        cout<<"5 : Delete node from last position\n";
        cout<<"6 : Delete node from given position\n";
        cout<<"7 : Display Linked List\n";
        cout<<"8 : Counter number of nodes from Linked List\n";
        cout<<"9 : Terminate the application\n";

        cin>>iChoice;

        cout<<"_________________________________\n";

        switch(iChoice)
        {
        case 1 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj2.InsertFirst(iValue);
            break;
        case 2 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj2.InsertLast(iValue);
            break;
        case 3 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            cout<<"Enter the position you want to insert : \n";
            cin>>iPosition;
            obj2.InsertAtPos(iValue, iPosition);
            break;
        case 4 :
            cout<<"Deleting First element : \n";
            obj2.DeleteFirst();
            break;
        case 5 :
            cout<<"Deleting Last element : \n";
            obj2.DeleteLast();
            break;
        case 6 :
            cout<<"Enter the position you want to delete : \n";
            cin>>iPosition;
            obj2.DeleteAtPos(iPosition);
            break;
        case 7 :
            obj2.Display();
            break;
        case 8 :
            cout<<"Number of elements are : "<<obj2.Count() <<"\n";
            break;
        case 9 :
            cout<<"Thank you for using the application\n";
            return 0;

        default :
            cout<<"Invalid choice\n";
            break;
        }

    }

        case 3:
            while (1)     //unconditional loop
    {
        cout<<"_________________________________\n";
        cout<<" Welcome to Doubly Linear Linked List . Please enter your choice : \n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node from first position\n";
        cout<<"5 : Delete node from last position\n";
        cout<<"6 : Delete node from given position\n";
        cout<<"7 : Display Linked List\n";
        cout<<"8 : Counter number of nodes from Linked List\n";
        cout<<"9 : Terminate the application\n";

        cin>>iChoice;

        cout<<"_________________________________\n";

        switch(iChoice)
        {
        case 1 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj3.InsertFirst(iValue);
            break;
        case 2 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj3.InsertLast(iValue);
            break;
        case 3 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            cout<<"Enter the position you want to insert : \n";
            cin>>iPosition;
            obj3.InsertAtPos(iValue, iPosition);
            break;
        case 4 :
            cout<<"Deleting First element : \n";
            obj3.DeleteFirst();
            break;
        case 5 :
            cout<<"Deleting Last element : \n";
            obj3.DeleteLast();
            break;
        case 6 :
            cout<<"Enter the position you want to delete : \n";
            cin>>iPosition;
            obj3.DeleteAtPos(iPosition);
            break;
        case 7 :
            obj3.Display();
            break;
        case 8 :
            cout<<"Number of elements are : "<<obj3.Count() <<"\n";
            break;
        case 9 :
            cout<<"Thank you for using the application\n";
            return 0;

        default :
            cout<<"Invalid choice\n";
            break;
        }

    }
        case 4:
            while (1)     //unconditional loop
    {
        cout<<"_________________________________\n";
        cout<<" Welcome to Doubly Circular Linked List . Please enter your choice : \n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node from first position\n";
        cout<<"5 : Delete node from last position\n";
        cout<<"6 : Delete node from given position\n";
        cout<<"7 : Display Linked List\n";
        cout<<"8 : Counter number of nodes from Linked List\n";
        cout<<"9 : Terminate the application\n";

        cin>>iChoice;

        cout<<"_________________________________\n";

        switch(iChoice)
        {
        case 1 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj4.InsertFirst(iValue);
            break;
        case 2 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            obj4.InsertLast(iValue);
            break;
        case 3 :
            cout<<"Enter the value you want to insert : \n";
            cin>>iValue;
            cout<<"Enter the position you want to insert : \n";
            cin>>iPosition;
            obj4.InsertAtPos(iValue, iPosition);
            break;
        case 4 :
            cout<<"Deleting First element : \n";
            obj4.DeleteFirst();
            break;
        case 5 :
            cout<<"Deleting Last element : \n";
            obj4.DeleteLast();
            break;
        case 6 :
            cout<<"Enter the position you want to delete : \n";
            cin>>iPosition;
            obj4.DeleteAtPos(iPosition);
            break;
        case 7 :
            obj4.Display();
            break;
        case 8 :
            cout<<"Number of elements are : "<<obj4.Count() <<"\n";
            break;
        case 9 :
            cout<<"Thank you for using the application\n";
            return 0;

        default :
            cout<<"Invalid choice\n";
            break;
        }
    }
        }

    }
 return 0;
}





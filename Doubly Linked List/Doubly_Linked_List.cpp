// Author Name: Harshdeep Singh Kanwar

// Doubly Linked List Implementation using C++

// Any corrections or suggestions are welcomed.

#include <iostream>

using namespace std;

// Creating a class Node that consists of data, a next pointer, a prev pointer of pointer to Node datatype.

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

// Creating a class DLL that consists of the head of Linked list and its methods implementation.

class DLL
{
    Node *head;

public:
    // This is a constructor that initializes the head to NULL when a new object of DLL class is created.
    DLL() { head = NULL; }

    // This is the display method implementation that prints the complete Linked list.
    void display()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        cout << "----------------------" << endl;

        Node *t = head;
        while (t != NULL)
        {
            cout << t->data << " <-> ";
            t = t->next;
        }
        cout << " X " << endl;
    }

    // This is the insertBeg method that is used to insert a node in the begining of the linked list.
    void insertBeg(int data)
    {
        if (head == NULL)
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            cout << "Inserted " << data << " at First pos " << endl;
            return;
        }

        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        cout << "Inserted " << data << " at First pos " << endl;
    }

    // This is the insertLast method that is used to insert a node in the end of the linked list.
    void insertLast(int data)
    {
        if (head == NULL)
        {
            insertBeg(data);
            cout << "Inserted " << data << " at Last pos " << endl;
            return;
        }

        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }

        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        temp->prev = t;
        t->next = temp;
        cout << "Inserted " << data << " at Last pos " << endl;
    }

    // This is the insertAt method that is used to insert a node at a specific position.
    void insertAt(int pos, int data)
    {
        if (pos > this->countNodes())
        {
            cout << "Invalid Position: cannot be greater than the number of nodes" << endl;
            return;
        }

        if (pos == 0)
        {
            cout << "Position starts from 1" << endl;
            return;
        }

        if (pos == 1)
        {
            insertBeg(data);
            return;
        }

        Node *t = head;

        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        if (t == NULL)
        {
            cout << "invalid pos " << pos << endl;
            return;
        }

        Node *temp = new Node();
        temp->data = data;
        temp->next = t->next;
        temp->prev = t;
        t->next = temp;
        cout << "Inserted : " << data << " at : " << pos << endl;
    }

    // This is the deleteAt method that is used to delete the node at a specific position.
    void deleteAt(int pos)
    {
        if (pos > this->countNodes())
        {
            cout << "Invalid Position: cannot be greater than the number of nodes" << endl;
            return;
        }

        if (pos == 1)
        {
            head = head->next;
            head->prev = NULL;
            cout << "deleted pos " << pos << endl;
            return;
        }

        Node *t = head;
        for (int i = 1; i < pos - 1; i++)
        {
            t = t->next;
        }
        if (t == NULL)
        {
            cout << "Invalid pos to be deleted at: " << pos << endl;
            return;
        }

        if (t->next == NULL)
        {
            cout << "Invalid pos to be deleted at " << pos << endl;
            return;
        }

        if (t->next->next == NULL)
        {
            t->next = NULL;
            cout << "deleted pos " << pos << endl;
            return;
        }

        t->next->next->prev = t;
        t->next = t->next->next;
        cout << "deleted pos " << pos << endl;
    }

    int countNodes()
    {
        int c = 0;
        if (head == NULL)
        {
            return 0;
        }

        Node *t = head;

        while (t != NULL)
        {
            c++;
            t = t->next;
        }
        return c;
    }
};

int main()
{
    cout << "Program Begins!!!" << endl;
    cout << endl;
    cout << endl;

    // Creating an object of class DLL.

    DLL dli;

    // While loop to take input continously until user wants to exit.

    while (true)
    {
        cout << "Choose from the following: " << endl;
        cout << "1. To insert in Beggining " << endl;
        cout << "2. To insert in the last " << endl;
        cout << "3. To insert at specific position. " << endl;
        cout << "4. Display the Linked List " << endl;
        cout << "5. To delete a specific node from linked list " << endl;
        cout << "6. Total number of nodes in linked list" << endl;
        cout << endl;
        cout << endl;
        cout << "TO EXIT ENTER 0 " << endl;
        cout << endl;
        cout << endl;

        int choice;
        cout << "Enter you choice: " << endl;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        else if (choice == 1)
        {
            cout << "Enter the data you want to insert: " << endl;
            short data;
            cin >> data;
            dli.insertBeg(data);
        }

        else if (choice == 2)
        {
            cout << "Enter the data you want to insert: " << endl;
            short data;
            cin >> data;
            dli.insertLast(data);
        }

        else if (choice == 3)
        {
            short data, pos;
            cout << "Enter the position at where you want to insert: " << endl;
            cin >> pos;
            cout << "Enter the data you want to insert: " << endl;
            cin >> data;
            dli.insertAt(pos, data);
        }

        else if (choice == 4)
        {
            dli.display();
        }

        else if (choice == 5)
        {
            short pos;
            cout << "Enter the pos you want to delete: " << endl;
            cin >> pos;
            dli.deleteAt(pos);
        }
        else if (choice == 6)
        {
            cout << "Count is: " << dli.countNodes() << endl;
        }

        else
        {
            cout << "Please Choose a valid option. " << endl;
        }

        cout << endl;
        cout << endl;
        cout << endl;
    }

    cout << "Program Ended Successfully" << endl;

    return 0;
}
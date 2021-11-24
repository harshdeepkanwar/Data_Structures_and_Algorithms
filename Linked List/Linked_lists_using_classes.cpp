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
};

// Creating a class LinkedList that consists of the head of Linked list and its methods implementation.

class LinkedList
{
public:
    Node *head;
    // This is a constructor that initializes the head to NULL when a new object of DLL class is created.
    LinkedList()
    {
        head = NULL;
    }

    // This is the insertBeg method that is used to insert a node in the begining of the linked list.
    void insertBeg(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    // This is the display method implementation that prints the complete Linked list.
    void display()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List " << endl;
            return;
        }
        Node *t = head;
        while (t != NULL)
        {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "X" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // This is the insertLast method that is used to insert a node in the end of the linked list.
    void insertLast(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }

    // This is the insertAt method that is used to insert a node at a specific position.
    void inserAt(int pos, int data)
    {
        if (pos > this->countNodes())
        {
            cout << "Invalid Position: cannot be greater than the number of nodes preseent" << endl;
            return;
        }

        if (pos == 0)
        {
            cout << "Invalid Position: Position starts from 1" << endl;
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
            cout << "Invalid Position. Try Again"
                 << " for " << data << endl;
            return;
        }

        Node *temp = new Node();
        temp->data = data;
        temp->next = t->next;
        t->next = temp;
    }

    // This is the findIn method that is used to find the specific node in linked list.
    int findIn(int data)
    {
        Node *t = head;
        int pos = 1;
        while (t != NULL)
        {
            if (t->data == data)
            {
                cout << data << " Found At : " << pos << endl;
                return pos;
            }
            pos++;
            t = t->next;
        }
        cout << "Not Found" << endl;
        return -1;
    }

    // This is the mid method that is used to find the mid node of the linked list.
    int mid()
    {
        if (this->countNodes() == 0)
        {
            cout << "Mid not found" << endl;
            return -1;
        }

        Node *f, *s;
        f = head;
        s = head;
        int c = 1;
        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
            c++;
        }

        cout << "Mid is At pos : " << c << " that is " << s->data << endl;
        return s->data;
    }

    // This is the maximum method that is used to find maximum value in linked list.
    int maximum()
    {
        if (this->countNodes() == 0)
        {
            cout << "No Maximum values" << endl;
            return -1;
        }

        int m = -1;
        Node *t = head;
        while (t != NULL)
        {
            if (t->data > m)
            {
                m = t->data;
            }
            t = t->next;
        }
        cout << "Maximum value in Linked List is: " << m << endl;
        return m;
    }

    // This is the deleteAt method that is used to delete the node at a specific position.
    void deleteAt(int pos)
    {
        if (pos > this->countNodes())
        {
            cout << "Invalid Position: cannot be greater than the number of nodes preseent" << endl;
            return;
        }

        Node *t = head;
        if (pos == 1)
        {
            cout << "Value deleted is: " << head->data << endl;
            head = head->next;
            return;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            if (t != NULL)
            {
                t = t->next;
            }
        }
        if (t->next == NULL)
        {
            cout << "Invalid position to be deleted :( " << endl;
            return;
        }

        cout << "Value deleted is: " << t->next->data << endl;

        t->next = t->next->next;
    }

    // This is the countNodes method that is used to count the total number of nodes in linked list.
    int countNodes()
    {
        if (head == NULL)
        {
            cout << "Count is 0: List is empty" << endl;
            return 0;
        }
        Node *t = head;
        int c = 0;
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

    // Creating an object of class LinkedList.

    LinkedList li;

    // While loop to take input continously until user wants to exit.

    while (true)
    {
        cout << "Choose from the following: " << endl;
        cout << "1. To insert in Beggining " << endl;
        cout << "2. To insert in the last " << endl;
        cout << "3. To insert at specific position. " << endl;
        cout << "4. Display the Linked List " << endl;
        cout << "5. To delete a specific node from linked list " << endl;
        cout << "6. To Count total number of nodes." << endl;
        cout << "7. To find a specific node in linked list." << endl;
        cout << "8. To find maximum value in linked list." << endl;
        cout << "9. To find mid node of linked list." << endl;
        cout << endl;
        cout << "TO EXIT ENTER 0 " << endl;
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
            li.insertBeg(data);
        }

        else if (choice == 2)
        {
            cout << "Enter the data you want to insert: " << endl;
            short data;
            cin >> data;
            li.insertLast(data);
        }

        else if (choice == 3)
        {
            short data, pos;
            cout << "Enter the position at where you want to insert: " << endl;
            cin >> pos;
            cout << "Enter the data you want to insert: " << endl;
            cin >> data;
            li.inserAt(pos, data);
        }

        else if (choice == 4)
        {
            li.display();
        }

        else if (choice == 5)
        {
            short pos;
            cout << "Enter the pos you want to delete: " << endl;
            cin >> pos;
            li.deleteAt(pos);
        }

        else if (choice == 6)
        {
            cout << "Count is: " << li.countNodes() << endl;
        }

        else if (choice == 7)
        {
            int data;
            cout << "Enter the data you want to search in linked list: " << endl;
            cin >> data;
            li.findIn(data);
        }

        else if (choice == 8)
        {
            li.maximum();
        }

        else if (choice == 9)
        {
            li.mid();
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
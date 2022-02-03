// Author Name: Harshdeep Singh Kanwar

// Doubly Linked List Implementation using C++

// Any corrections or suggestions are welcomed.

#include <iostream>
using namespace std;

// Creating a class Node that consists of data, a next pointer of (pointer to Node datatype).

class Node
{
public:
    int data;
    Node *next;
};

// Creating a class Queue in which we'll use the linked list created using above class and determine queue's methods

class Queue
{
private:
    Node *head;
    Node *rear;
    Node *front;

public:
    // This is a constructor that initializes head, rear and front to NULL initially ie. queue is empty
    Queue()
    {
        head = NULL;
        rear = NULL;
        front = NULL;
    }
    // This is the enqueue method that inserts new value to queue from rear
    void enq(int data)
    {
        if (head == NULL)
        {
            head = new Node(); // allocating memory to head
            head->data = data;
            head->next = NULL;
            front = head;
            rear = head;
        }
        else
        {
            Node *temp = new Node();
            if (temp)
            {
                temp->data = data;
                temp->next = NULL;
                rear->next = temp;
                rear = temp;
            }
            else
            {
                cout << "queue is full (memory full) " << endl;
            }
        }
    }
    // This method show the data present at the rear ie. last element in the queueu
    void peek()
    {
        if (head != NULL)
        {
            cout << rear->data << endl;
        }
        else
        {
            cout << "empty" << endl;
        }
    }
    // This is deque method that removes the value form queue from front
    int deq()
    {
        if (head != NULL)
        {
            head = head->next;
            int val = front->data;
            Node *ptr = front;
            front = head;
            delete ptr;
            return val;
        }
        else
        {
            cout << "empty" << endl;
            return -1;
        }
    }
    // This is print/display method just to print the queue at any time
    void printq()
    {
        if (!head)
        {
            cout << "Empty" << endl;
            return;
        }

        Node *itr = front;
        while (itr != NULL)
        {
            cout << "value is: " << itr->data << " ";
            itr = itr->next;
        }
        cout << endl;
    }
};

int main()
{
    //MENU DRIVEN PROGRAM
    cout << "Program Begins!!!" << endl;
    cout << endl;
    cout << endl;
    // Creating an object of class Queue
    Queue q;

    // While loop to take input continously until user wants to exit.

    while (true)
    {

        cout << "Choose from the following: " << endl;
        cout << "1. To push into Queue " << endl;
        cout << "2. To pop from Queue " << endl;
        cout << "3. Display Stack " << endl;
        cout << "4. Peek " << endl;
        cout << endl;
        cout << "To EXIT ENTER 0 " << endl;

        int choice;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        else if (choice == 1)
        {
            int data;
            cout << "Enter value you want to push into Queue: " << endl;
            cin >> data;
            q.enq(data);
        }

        else if (choice == 2)
        {
            int val;
            val = q.deq();
            if (val == -1)
            {
                cout << "Queue Cannot pop any value" << endl;
            }
            else
            {
                cout << "Popped value is: " << val << endl;
            }
        }

        else if (choice == 3)
        {
            q.printq();
        }

        else if (choice == 4)
        {
            q.peek();
        }

        else
        {
            cout << "Choose a valid option " << endl;
        }

        cout << endl;
        cout << endl;
    }

    cout << "Program Ended Successfully" << endl;

    return 0;
}
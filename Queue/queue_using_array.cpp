// Author Name: Harshdeep Singh Kanwar

// Doubly Linked List Implementation using C++

// Any corrections or suggestions are welcomed.

#include <iostream>
using namespace std;

// Creating a class Queue in which we'll use the linked list created using above class and determine queue's methods
class Queue
{
private:
    int capacity; // total capacity of queue
    int front;
    int rear;
    int *arr; // integer pointer 
    // we'll use this integer pointer to point to an integer type array which we'll declare at runtime when the user inputs capacity 
    // We'll do this in constructor.

public:
    // This is the constructor here we'll take required inputs from the user and initialize the array.
    Queue()
    {
        cout << "capacity: " << endl;
        cin >> capacity;
        front = rear = -1;
        cout << "front: " << front << " rear: " << rear << endl;
        arr = new int[capacity];
        cout << "array created of index = capacity " << endl;
    }
    // This is the enqueue method that inserts new value to queue from rear
    void enq(int data)
    {
        if (rear < capacity - 1)
        {
            rear++;
            if (front == -1)
            {
                front++;
            }
            arr[rear] = data;
        }
        else
        {
            cout << "q is full " << endl;
        }
    }
    // This is the dequeue method that removes the value form queue from front
    int deq()
    {
        if(front==-1 && rear==-1){
            return -1;
        }

        if (front <= rear)
        {
            int val = arr[front];
            front++;
            if (front > rear)
            {
                front = rear = -1;
            }
            return val;
        }
        else
        {
            cout << "q is empty " << endl;
            return -1;
        }
    }
    // This is the print/display method just to print queue at any time
    void printq()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "value at " << i << " " << arr[i] << endl;
        }

        // You can uncomment the following lines of code to see the values of front and rear with each occuring operation.
        
        // cout << "rear at: " << rear << endl;
        // cout << "front at: " << front << endl;
    }
    // This method shows data present at rear ie. last element in queue
    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "q is empty " << endl;
        }
        else
        {
            cout << arr[rear] << endl;
        }
    }
};

int main()
{
    // MENU DRIVEN PROGRAM
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
// Author Name: Harshdeep Singh Kanwar

// Stack Implementation using Arrays in  C++

// Any corrections or suggestions are welcomed.

#include <iostream>

using namespace std;

// Creating class Stack that will consist all the methods of Stack

class Stack
{
private:
    int s;
    int top;
    int *arr;

public:
    // This is a constructor that takes stack size as input and declares the required arr of same size dynamically.

    Stack()
    {
        cout << "Enter the size of stack to be created: " << endl;
        cin >> s;
        arr = new int[s - 1];
        cout << "Stack object created of size: " << s << endl;
        top = -1;
    }

    // This is a method to check whether the stack is Empty or not

    bool isEmpty()
    {
        return (top == -1);
    }

    // This is a method to check whether a stack is Full or not

    bool isFull()
    {
        return (top == s - 1);
    }

    // This is the method that displays the complete stack

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty " << endl;
            return;
        }

        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }

    // This is method that pushes the new values into the stack

    void push(int data)
    {
        cout << "You Entered: " << data << endl;
        if (!isFull())
        {
            arr[++top] = data;
            cout << data << " pushed successfully " << endl;
        }
        else
        {
            cout << "Stack Overflow : Cannot push more values" << endl;
            return;
        }
    }

    // This is a method that gives info about top variable

    void topValue()
    {
        if (top == -1)
        {
            cout << "Index of top is: " << top << endl;
            return;
        }
        cout << "Value at top is: " << arr[top] << endl;
        cout << "Index of top is: " << top << endl;
    }

    // This is a method that returns the top value and removes it from the stack

    int pop()
    {
        if (!isEmpty())
        {
            //cout << "Popped value is: " << arr[top--] << endl;
            return arr[top--];
        }
        else
        {
            return -1;
        }
    }

    // This is a method that returns us the value at specific position in a stack

    int peek(int pos)
    {
        int i;
        i = top - pos + 1;
        if (pos > 0)
        {
            if (!isEmpty())
            {
                if (i >= 0)
                {
                    return arr[i];
                }
            }
        }

        return -1;
    }
};

int main()
{
    cout << "Program Begins!!!" << endl;

    // Creating an object of class LinkedList.

    Stack st;

    // While loop to take input continously until user wants to exit.

    while (true)
    {

        cout << "Choose from the following: " << endl;
        cout << "1. To push into Stack " << endl;
        cout << "2. To pop from Stack " << endl;
        cout << "3. Display Stack " << endl;
        cout << "4. Info at TOP " << endl;
        cout << "5. isEmpty() " << endl;
        cout << "6. isFull() " << endl;
        cout << "7. Peek() " << endl;
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
            cout << "Enter value you want to push into stack: " << endl;
            cin >> data;
            st.push(data);
        }

        else if (choice == 2)
        {
            int val;
            val = st.pop();
            if (val == -1)
            {
                cout << "Stack Underflow : Cannot pop any value" << endl;
            }
            else
            {
                cout << "Popped value is: " << val << endl;
            }
        }

        else if (choice == 3)
        {
            st.display();
        }

        else if (choice == 4)
        {
            st.topValue();
        }

        else if (choice == 5)
        {
            if (st.isEmpty())
            {
                cout << "Stack is Empty " << endl;
            }
            else
            {
                cout << "Not Empty" << endl;
            }
        }

        else if (choice == 6)
        {
            if (st.isFull())
            {
                cout << "Stack is Full " << endl;
            }
            else
            {
                cout << "Not Full " << endl;
            }
        }

        else if (choice == 7)
        {
            int pos;
            cout << "Enter the position you want to peek: " << endl;
            cin >> pos;
            int val;
            val = st.peek(pos);
            if (val == -1)
            {
                cout << "Invalid position to peek" << endl;
            }
            else
            {
                cout << "Value at " << pos << " is: " << val << endl;
            }
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
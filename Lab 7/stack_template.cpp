#include <iostream>

using namespace std;

template <class T>
class Stack
{
    int size;
    int top;
    T *arr;

    public:
        Stack(int size)
        {
            this->size = size;
            this->top = -1;
            this->arr = new T[size];
        }

        // Copy constructor
        Stack(Stack &s)
        {
            this->size = s.size;
            this->top = s.top;
            this->arr = new T[size];

            for (int i = 0; i <= top; i++)
            {
                arr[i] = s.arr[i];
            }
        }

        void push(T e)
        {
            if (size - 1 == top)
            {
                extend();
            }
            top++;
            arr[top] = e;
        }

        void pop()
        {
            if (-1 != top)
            {
                cout << "Poped: " << arr[top] << endl;
                top--;
            }
            else
            {
                cout << "Cannot pop, stack is empty!" << endl;
            }
        }

        void display()
        {
            if (-1 == top)
            {
                cout << "Current stack: empty";
            }
            else
            {
                cout << "Current stack: ";
                for (int i = 0; i <= top; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        void extend()
        {
            this->size *= 2;
            T *new_arr = new T[size];
            for (int i = 0; i <= top; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }

        ~Stack()
        {
            delete[] arr;
        }
};

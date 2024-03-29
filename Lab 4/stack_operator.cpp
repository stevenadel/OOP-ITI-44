#include <iostream>

using namespace std;

class Stack
{
    int size;
    int top;
    int *arr;

    public:
        Stack(int size)
        {
            this->size = size;
            this->top = -1;
            this->arr = new int[size];
        }

        // Copy constructor
        Stack(Stack &s)
        {
            this->size = s.size;
            this->top = s.top;
            this->arr = new int[size];

            for (int i = 0; i <= top; i++)
            {
                arr[i] = s.arr[i];
            }
        }

        void push(int e)
        {
            if (size - 1 == top)
            {
                cout << "Cannot push, stack is full!";
            }
            else
            {
                top++;
                arr[top] = e;
            }
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

        void operator = (Stack s)
        {
            size = s.size;
            top = s.top;
            delete arr;

            this->arr = new int[size];
            for (int i = 0; i <= top; i++)
            {
                arr[i] = s.arr[i];
            }
        }

        ~Stack()
        {
            delete[] arr;
        }
};

int main()
{
    Stack s1(7);
    Stack s2 = s1;
}

#include <iostream>

using namespace std;

class Stack
{
    friend int main();
    int size;
    int top;
    int *arr;

    public:
        Stack(int size)
        {
            this->size = size;
            this->top = -1;
            arr = new int[size];
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
                cout << arr[top] << endl;
                top--;
            }
            else
            {
                cout << "Cannot pop, stack is empty!";
            }
        }

        void display()
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }

        ~Stack()
        {
            delete[] arr;
        }
};

int main()
{
    Stack stk = *(new Stack(10));
    stk.push(8);
    stk.push(5);
    stk.push(3);
    stk.pop();
    stk.push(9);
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();

    cout << "\n\n" << "Current stack: ";
    //stk.display();
    cout << endl;
    return 0;
}

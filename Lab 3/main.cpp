#include <iostream>
#include "stack.h"

using namespace std;

void stackCopy(Stack s);

int main()
{
    Stack s1 = *(new Stack(10));
    s1.push(3);
    s1.push(15);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.push(50);
    s1.push(25);

    // Shallow or deep copy, depending on copy constructor
    // being explicitly implemented or implicit default
    stackCopy(s1);

    s1.push(32);
    s1.push(86);
    s1.display();
    return 0;
}

void stackCopy(Stack s)
{
    s.display();
    s.pop();
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.display();
}

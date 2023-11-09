#include <iostream>

using namespace std;

class Queue
{
    int size;
    int fr, bk;
    int *arr;

    public:
        Queue(int size)
        {
            this->size = size;
            this->fr = -1;
            this->bk= -1;
            arr = new int[size];
        }

        void enqueue(int e)
        {
            if (-1 == fr)
            {
                fr = 0;
            }

            if (size - 1 == bk)
            {
                cout << "Cannot enqueue, queue is full!";
            }
            else
            {
                bk++;
                arr[bk] = e;
                //cout << "Enqueued: " << arr[bk] << endl;
            }
        }

        void dequeue()
        {
            if (-1 != fr)
            {
                cout << "Dequeued: " << arr[fr] << endl;
                if (fr == bk)
                {
                    fr = -1;
                    bk = -1;
                }
                else
                {
                    fr++;
                }
            }
            else
            {
                cout << "Cannot dequeue, queue is empty!" << endl;
            }
        }

        void display()
        {
            if (-1 == fr)
            {
                cout << "empty" << endl;
            }
            else
            {
                for (int i = fr; i <= bk; i++)
                {
                    cout << arr[i] << " ";
                }
            }
        }

        ~Queue()
        {
            delete[] arr;
        }
};

int main()
{
    Queue qu = *(new Queue(10));
    qu.enqueue(3);
    qu.enqueue(5);
    qu.enqueue(5);
    qu.dequeue();  //3
    qu.dequeue(); //5
    qu.enqueue(10);
    qu.dequeue();//5
    qu.dequeue();//10
    qu.dequeue();//empty
    qu.dequeue();//empty

    cout << "\n\n" << "Current queue: ";
    qu.display();
    return 0;
}

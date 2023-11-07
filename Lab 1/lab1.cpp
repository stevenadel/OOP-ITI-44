#include <iostream>

using namespace std;

class Complex
{
    friend void subtractFriend(Complex &c1, Complex &c2);
    int real;
    int imaginary;

    public:
        Complex(int real, int imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        int getReal()
        {
            return real;
        }

        void setReal(int real)
        {
            this->real = real;
        }

        int getImaginary()
        {
            return imaginary;
        }

        void setImaginary(int imaginary)
        {
            this->imaginary = imaginary;
        }

        void add(Complex comp)
        {
            real += comp.real;
            imaginary += comp.imaginary;
        }

        void subtract(Complex comp)
        {
            real -= comp.real;
            imaginary -= comp.imaginary;
        }
};

Complex add(Complex c1, Complex c2);
Complex subtract(Complex c1, Complex c2);
void subtractFriend(Complex &c1, Complex &c2);
void swapAddress(int *x,int *y);
void swapReference(int &x, int &y);

int main()
{
    //Complex c1(4,3), c2(1,2);
    //Complex &ref1 = c1, &ref2 = c2;
    //c1.add(c2);
    //cout << add(c1, c2).getReal() << endl;
    //c1.subtract(c2);
    //subtractFriend(ref1, ref2);
    //cout << c1.getReal() << endl;
    return 0;
}

Complex add(Complex c1, Complex c2)
{
    Complex c3(0,0);
    c3.setReal(c1.getReal() + c2.getReal());
    c3.setImaginary(c1.getImaginary() + c2.getImaginary());
    return c3;
}

Complex subtract(Complex c1, Complex c2)
{
    Complex c3(0,0);
    c3.setReal(c1.getReal() - c2.getReal());
    c3.setImaginary(c1.getImaginary() - c2.getImaginary());
    return c3;
}

void subtractFriend(Complex &c1, Complex &c2)
{
    c1.real -= c2.real;
    c1.imaginary -= c2.imaginary;
}

void swapAddress(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swapReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

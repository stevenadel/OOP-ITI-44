#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

    public:
        Complex(int real, int imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        void setComplex(int real, int imaginary)
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

        void printComplex()
        {
            cout << real;
            if (imaginary > 0)
            {
                cout << "+";
            }
            cout << imaginary << "j";
        }

        Complex operator + (Complex c)
        {
            return Complex(real + c.getReal(), imaginary + c.getImaginary());
        }

        Complex operator + (int i)
        {
            return Complex(real + i, imaginary);
        }

        Complex operator - (Complex c)
        {
            return Complex(real - c.getReal(), imaginary - c.getImaginary());
        }

        Complex operator - (int i)
        {
            return Complex(real - i, imaginary);
        }

        Complex operator = (Complex c)
        {
            return Complex(c.getReal(),c.getImaginary());
        }

        int operator == (Complex c)
        {
            return this->real == c.getReal() && this->imaginary == c.getImaginary();
        }

        void operator += (Complex c)
        {
            real += c.getReal();
            imaginary += c.getImaginary();
        }

        Complex operator ++ ()
        {
            return Complex(++real, ++imaginary);
        }

        Complex operator ++ (int)
        {
            return Complex(real++, imaginary++);
        }

        operator float()
        {
            return real;
        }
};

Complex operator + (int i, Complex c)
{
    return Complex(c.getReal() + i, c.getImaginary());
}

Complex operator - (int i, Complex c)
{
    return Complex(i - c.getReal(), c.getImaginary());
}

int main()
{
    Complex c1(4,-3), c2(1,2);
    Complex c3 = 5 + c2;
    (c3++).printComplex();
    return 0;
}

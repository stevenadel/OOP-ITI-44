#include <iostream>
#include <string.h>

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
            cout << imaginary << "j" << endl;
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

        int operator [] (int i)
        {
            if (0 == i)
            {
                return real;
            }
            if (1 == i)
            {
                return imaginary;
            }
        }

        int operator [] (char *s)
        {
            if (!strcmp("real", s))
            {
                return real;
            }
            if (!strcmp("imaginary", s))
            {
                return imaginary;
            }
            return 0;
        }

        friend istream &operator >> (istream &input, Complex &c)
        {
            input >> c.real >> c.imaginary;
            return input;
        }

        friend ostream &operator << (ostream &output, Complex &c)
        {
            output << c.getReal();
            if (c.getImaginary() > 0)
            {
                output << "+";
            }
            output << c.getImaginary() << "j" << endl;
            return output;
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
    cin >> c3;
    cout << c3;
    return 0;
}

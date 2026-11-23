
#include <iostream>
using namespace std;

class Complex
{
    float real, imag;

public:

    // Default constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterized constructor
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Overloading + operator
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Overloading * operator
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    // Friend function declarations
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

// Overloading >> operator for input
istream& operator>>(istream& in, Complex& c)
{
    cout << "Enter real part: ";
    in >> c.real;

    cout << "Enter imaginary part: ";
    in >> c.imag;

    return in;
}

// Overloading << operator for output
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real;

    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";

    return out;
}

int main()
{
    Complex c1, c2, sum, product;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "\nEnter second complex number:\n";
    cin >> c2;

    sum = c1 + c2;
    product = c1 * c2;

    cout << "\nFirst complex number: " << c1 << endl;
    cout << "Second complex number: " << c2 << endl;

    cout << "Addition: " << sum << endl;
    cout << "Multiplication: " << product << endl;

    return 0;
}

/*
Problem Statement:
Implement a class Complex which represents the Complex
Number data type. Implement the following:

a. Constructor including a default constructor which
   creates the complex number 0+0i.
b. Overload operator + to add two complex numbers.
c. Overload operator * to multiply two complex numbers.
d. Overload operators << and >> to print and read
   Complex Numbers.

Sample Output:

Enter first complex number:
Enter real part: 3
Enter imaginary part: 4

Enter second complex number:
Enter real part: 1
Enter imaginary part: 2

First complex number: 3 + 4i
Second complex number: 1 + 2i
Addition: 4 + 6i
Multiplication: -5 + 10i

*/

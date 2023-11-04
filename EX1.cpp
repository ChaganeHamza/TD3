#include <iostream>

using namespace std;

class Complex {
public:
    float real, imag;

    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    Complex operator +(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator -(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator *(Complex c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator /(Complex c) {
        float denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom, (real * c.imag - imag * c.real) / denom);
    }

    void display() {
        cout << real << " + i" << imag << endl;
    }
};

int main() {
    float real1, imag1, real2, imag2;
    cout << "Enter the real and imaginary part of the first complex number: ";
    cin >> real1 >> imag1;
    cout << "Enter the real and imaginary part of the second complex number: ";
    cin >> real2 >> imag2;

    Complex c1(real1, imag1), c2(real2, imag2);
    Complex c3 = c1 + c2, c4 = c1 - c2, c5 = c1 * c2, c6 = c1 / c2;

    cout << "Sum: "; c3.display();
    cout << "Difference: "; c4.display();
    cout << "Product: "; c5.display();
    cout << "Quotient: "; c6.display();

    return 0;
}
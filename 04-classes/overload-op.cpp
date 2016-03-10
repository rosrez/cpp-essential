#include <cstdio>
#include <iostream>
using namespace std;

// Note the naming convention: rhs - right hand side operand

class Rational {
    int _n = 0;
    int _d = 1;
public:
    // regular constructor: value defaults to 0/1.
    Rational (int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {};
    // copy constructor
    Rational (const Rational & rhs) : _n(rhs._n), _d(rhs._d) {};
    ~Rational();

    // getters
    inline int numerator() const { return _n; };
    inline int denominator() const { return _d; };
    // operator overloads
    Rational & operator=(const Rational &);
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;
    Rational operator<<(const Rational &) const;
};

Rational & Rational::operator=(const Rational & rhs) {
    if (this != &rhs) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;   // allows chaining assignments, i.e. a = b = c
}

Rational Rational::operator+(const Rational & rhs) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator-(const Rational & rhs) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator*(const Rational & rhs) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator/(const Rational & rhs) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::~Rational() {
    printf("dtor %d/%d\n", _n, _d);
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator<<(std::ostream & o, const Rational & r) {
    return o << r.numerator() << '/' << r.denominator();
}

int main(int argc, char *argv[]) {
    // Implicit type conversion
    Rational a = 7;     // 7/1
    cout << "a is: " << a << endl;
    // Regular constructor
    Rational b(5,3);    // 5/3
    cout << "b is: " << b << endl;
    // Copy constructor
    Rational c = b;
    cout << "c is: " << c << endl;
    // Default constructor
    Rational d;
    cout << "d is: " << d << endl;
    // Assignment operator
    d = c;
    cout << "d new value is: " << d << endl;
    // Reference
    Rational & e = d;
    // Assignment to self!
    d = e;
    cout << "e is: " << e << endl;

    // Arithmetic operations: call operator overload methods
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    // Since our copy constructor returns 'this', 
    // the result can be used as the right hand side expression 
    // for another assignment
    a = b = c = d;
    cout << "a now is: " << a << endl;
    cout << "b now is: " << b << endl;
    cout << "c now is: " << c << endl;
    cout << "d now is: " << d << endl;

    return 0;

}

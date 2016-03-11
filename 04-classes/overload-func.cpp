#include <cstdio>
#include <iostream>
using namespace std;

class Rational {
    int _n;
    int _d;
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
    // We take out operator+() and move it outside the class.
    // Rational operator+(const Rational &) const;
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

// We substituted this class operator with a overloaded + operator
// for Rational.
#if 0
Rational Rational::operator+(const Rational & rhs) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}
#endif

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

Rational operator+(const Rational & lhs, const Rational & rhs) {
    return Rational(lhs.numerator() * rhs.denominator() + lhs.denominator() * rhs.numerator(), 
            lhs.denominator() * rhs.denominator());
}

int main(int argc, char *argv[]) {
    // Implicit type conversion
    Rational a = 7;     // 7/1
    cout << "a is: " << a << endl;
    // Regular constructor
    Rational b(5,3);    // 5/3

    // Arithmetic operations: call operator overload methods
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    // Left-hand operand is not Rationale, just implicitly converted to one
    // This is why we needed to define the + operator outside the class
    cout << "operator+ from outside the class:" << endl;
    cout << 14 << "  " << a << " = " << 14 + a << endl;
    return 0;
}

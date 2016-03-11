#include <cstdio>
#include <iostream>
using namespace std;

// Note the naming convention: rhs - right hand side operand

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
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;
    Rational operator<<(const Rational &) const;
    // converts our object to std::string type
    operator std::string() const;
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

// operator to convert Rational string
Rational::operator std::string() const {
    const static int maxstring = 64;
    char s[maxstring];
    snprintf(s, maxstring, "%d/%d", _n, _d);
    return std::string(s);
}

int main(int argc, char *argv[]) {
    Rational b(5,3);    // 5/3
    string s = "Rational as a string: ";
    s += b;     // append string representation of b to s: calls our conversion operator

    cout << s << endl;
    return 0;

}

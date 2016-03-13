#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename lhsT, typename rhsT>

// C++11 feature: trailing return type

// + - COMPILER DOESN'T KNOW WHAT THE RETURN TYPE WILL BE
// |                             + - TELLS THE COMPILER TO USE THE TYPE
// |                             |   OF lhs + rhs EXPRESSION AS RETURN TYPE
// V                             V
auto tf(lhsT & lhs, rhsT & rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}

int main(int argc, char *argv[]) {
    int i = 47;
    const char * cstr = "this is a c-string";
    string strobj("this is a string class string");

    auto x = string("this is a string class string");

    // A type declaration based on the type of the expression
    // Here, y has the same type as x.
    decltype(x) y;

    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of strobj is " << typeid(strobj).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;

    // Here, auto means that the return type is not known at this point.
    auto z = tf(cstr, strobj);
    cout << "z is " << z << endl;   // the result is the concatenation of both strings
    cout << "type of z is " << typeid(z).name() << endl;    // the type is std::string

    return 0;
}

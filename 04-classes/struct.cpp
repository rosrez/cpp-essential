#include <cstdio>
using namespace std;

// This is actually equivalent to defining a class
// with public members ia, ib and ic.
// So, the difference between struct and class
// is that struct defaults to public members
// and class defaults to private members.

// struct is a good way of creating data-only classes,
// without any methods.
struct A {
    int ia;
    int ib;
    int ic;
};

int main(int argc, char *argv[])
{
    // Note that we don't use the 'struct' keyword, since A is a class.
    A a = {1, 2, 3};

    printf("ia is %d, ib is %d, ic is %d\n", a.ia, a.ib, a.ic);
    return 0;
}

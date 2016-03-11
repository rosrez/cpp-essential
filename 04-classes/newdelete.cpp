#include <cstdio>
#include <new>
using namespace std;

class A {
    int _a;
    int _b;
    int _c;
public:
    A(int i = 0);
    ~A();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
};

A::A(int i) : _a(i), _b(i + 1), _c(i + 2) {
    puts("A constructor called");
}

A::~A() {
    puts("A destructor called");
}

int main(int argc, char *argv[])
{
    puts("A SINGLE OBJECT");
    puts("allocating space for one A object");
    // new allocates space, places an object there
    // and calls the class's constructor
    A * a = new (nothrow) A(5);
    // nullptr is a C++ 11 feature.
    if (a == nullptr) {
        puts("new A failed");
        return 1;
    }
    printf("a: %d, %d, %d\n", a->a(), a->b(), a->c());
    // calls destructor and then frees memory 
    delete a;
    puts("A object has been deleted");
    puts("----------------\n");

    puts("MULTIPLE OBJECTS");
    puts("allocating space for multiple objects");
    
    // Note the (nothrow) option to new, it
    // suppresses new from throwing exceptions if
    // there is no memory.
    // In this case, all we need is test if the return
    // value is equal to nullptr, in which case
    // this is an indication that new faled.
    
    // new A[3] - creates three objects, placed 
    // contiguously in memory.
    A * b = new (nothrow) A[3];
    // nullptr is a C++ 11 feature.
    if (b == nullptr) {
        puts("new A failed");
        return 1;
    }
    printf("b: %d, %d, %d\n", b->a(), b->b(), b->c());

    // delete [] deletes an array of objects at once
    delete [] b;
    puts("Objects have been deleted");
    puts("----------------\n");

    return 0;
}

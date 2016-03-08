#include <cstdio>
using namespace std;

class A {
private:
    int ia;
public:
    void setvalue(const int a);

    // we can have two (getter) methods with the same signature, apart from the const keyword!
    int getvalue();
    int getvalue() const;   // const after parentheses makes the method const-safe
};

void A::setvalue(const int a) {
    ia = a;
}

// gets called by mutable instances of A
int A::getvalue() {
    puts("mutable getter");
    return ia;
}

// gets called by immutable instances of A
int A::getvalue() const {   // again, we need to put 'const' after the parentheses to make the method const-safe
    puts("const getter");
    return ia;
}

int main(int argc, char *argv[])
{
    A a;
    a.setvalue(42);

    const A b = a;  // wouldn't compile without making getvalue() const-safe

    printf("a value is %d\n", a.getvalue());    // calls mutable getvalue()

    // the following line wouldn't compile without making getvalue const-safe
    printf("value is %d\n", b.getvalue());  // calls immutable getvalue() - 
    return 0;
}

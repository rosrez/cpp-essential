#include <cstdio>
using namespace std;

class Class1 {
    int i;
public:
    Class1() : i(0) {}
    void setvalue(const int value) { i = value; }
    int getvalue() const;
};

int Class1::getvalue() const {
    printf("getvalue(): this is %p\n", this);
    return i;
}

int main(int argc, char *argv[]) {
    int i = 47;
    Class1 object1;

    object1.setvalue(i);
    printf("object1.value() is %d\n", object1.getvalue());
    printf("object1 is %p -- identical to 'this' from method invocation\n", &object1);

    return 0;
}

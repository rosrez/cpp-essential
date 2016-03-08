#include <cstdio>
using namespace std;

// A basic class
class Class1 {
// Members of a class default to private, so
// we could have omitted the keyword private: here.
private:
    int i;
public:
    void setvalue(const int value) { i = value; }
    int getvalue() const { return i; }
};

// Another class that's identical to Class1,
// but method implementations are defined outside
// the class definition.

// Note that a class definition usually goes into a header file,
// and class implementation goes into a separate source file.
class Class2 {
private:
    int i;
public:
    void setvalue(const int value); 
    int getvalue() const;
};

void Class2::setvalue(const int value) {
    i = value;
}

int Class2::getvalue() const {
    return i;
}

int main(int argc, char *argv[])
{
    int i = 47;
    Class1 obj1;
    Class1 obj2;

    obj1.setvalue(i);
    obj2.setvalue(73);
    printf("obj1 value is %d\n", obj1.getvalue());
    printf("obj2 value is %d\n", obj2.getvalue());
    return 0;
}

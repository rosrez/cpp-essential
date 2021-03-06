#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

// -- interface --

// The constructor name must be spelled exactly as the class's name.
// The destructor is the name of the class preceded by a tilde character (~).

// Note the 'rule of 3': if we are to provide our own copy constructor, copy operator
// or destructor, it's best to provide all three of them.

class Animal {
    string _type;
    string _name;
    string _sound;

    // We could have moved the default constructor here, to prevent
    // anyone from using the default constructor, if we needed to.
public:
    // default constructor -- public
    Animal();
    Animal(const string & type, const string & name, const string & sound);

    // copy constructor
    Animal(const Animal &);
    // copy operator
    Animal & operator=(const Animal &); 
    // destructor
    ~Animal();
    void print() const;
};

// -- implementation --

// INITIALIZER LIST ---V ---------V ----------V
Animal::Animal(): _type(unk), _name(unk), _sound(unk) {
    puts("default constructor -------------");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments -------");
}

Animal::Animal(const Animal & a) {
    puts("copy constructor -----------");
    _name = clone_prefix + a._name;
    _type = a._type;
    _sound = a._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator=(const Animal & o) {
    puts("assignment operator ---------------");
    if (this != &o) {
        _name = clone_prefix + o._name;     // a derived objects name will be prefixed with 'clone-'
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
}

int main(int argc, char *argv[])
{
    // Calls the default constructor
    Animal a;
    a.print();

    // Calls the constructor with arguments
    const Animal b("goad", "bob", "baah");
    b.print();

    // Assign an existing object to a new object: calls the copy constructor
    const Animal c = b;
    c.print();

    // Assign an existing object to an existing object: calls the copy operator
    a = c;
    a.print();

    return 0;
}

#include <cstdio>
#include <string>
using namespace std;

class Animal {
    string _name;
    string _type;
    string _sound;

    // private constructor prevents construction of base class
    Animal(){};
protected:
    // protected constructor for use by derived classes
    Animal(const string & n, const string & t, const string & s)
    : _name(n), _type(t), _sound(s) {}
public:
    void speak() const;
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal

// Note that we call the (protected) Animal() constructor
// to initialize fields that pertain to Animal. If we 
// wanted to initialize those fields in a regular fashion,
// we would need to declare them in Animal as protected.
// This would be cumbersome and is not really recommended.

// ACCESS SPECIFIER BASE CLASS
//            |       |
//            V       V
class Dog : public Animal {
    int walked;
public:
    // BASE CLASS CONSTRUCTOR         VARIABLE INITIALIZER
    //                V                           V
    Dog(string n) : Animal(n, "dog", "woof"), walked(0) {};
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
class Cat : public Animal {
    int petted;
public:
    Cat(string n) : Animal(n, "cat", "meow"), petted(0) {};
    int pet() { return ++petted; }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int fed;
public:
    Pig(string n) : Animal(n, "pig", "oink"), fed(0) {};
    int feed() { return ++fed; }
};

int main(int argc, char *argv[]) {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");

    d.speak();
    c.speak();
    p.speak();

    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the pig has been fed %d times\n", p.feed());
    return 0;
};

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
    // a virtual method: allow polymorphic behavior of speak()
    virtual void speak() const;
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
    void speak() const;
};

void Cat::speak() const {
    printf("purr\n");
}

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

    Animal *ap[] = { &d, &c, &p };

    // Since we refer to our objects through a base class,
    // calling a method that is defined in the base class
    // (here, speak()) will invoke the base class's method,
    // even if we have overloaded that method in a derived
    // class.
    // In order to be able to call a derived class's
    // method in situations like this, we need to declare
    // the method as virtual IN THE BASE CLASS (!).
    // In other words, now our pointer to the base class
    // becomes polymorphic.
    for (Animal *a : ap) {
        a->speak();
    }
    return 0;
};

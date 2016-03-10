#include <cstdio>
using namespace std;

const size_t _maxsize = 1024;

// This class has *explicit* constructors, which can only get called
// by explicitly invoking a class constructor, such as this:
//
// s("1234");

class strsize {
    size_t _size = 0;
public:
    explicit strsize(const int);     // constructor: size from int
    explicit strsize(const char *);  // constructor: size from c-string
    size_t size() const;
};

// takes the size from an integer
strsize::strsize(const int n) {
    puts("constructor: size from int");
    _size = ((size_t) n <= _maxsize) ? n : 0;
}

// takes the size to be equal to size of string
strsize::strsize(const char * s)
{
    puts("constructor: size from c-string");
    for (size_t i = 0; i < _maxsize; i++) {
        if (s[i] == 0) {
            _size = i;
            return;
        }
    }
    _size = 0;
}

size_t strsize::size() const {
    return _size;
}

// ===================================
// strsize_i has exactly the same functionality as strsize above.
// The difference is that this class defines its constructors
// as *implicit*, which allow some implicit conversions while 
// objects of this class are being created. See below for details

class strsize_i {
    size_t _size = 0;
public:
    strsize_i(const int);     // constructor: size from int
    strsize_i(const char *);  // constructor: size from c-string
    size_t size() const;
};

// takes the size from an integer
strsize_i::strsize_i(const int n) {
    puts("constructor: size from int");
    _size = ((size_t) n <= _maxsize) ? n : 0;
}

// takes the size to be equal to size of string
strsize_i::strsize_i(const char * s)
{
    puts("constructor: size from c-string");
    for (size_t i = 0; i < _maxsize; i++) {
        if (s[i] == 0) {
            _size = i;
            return;
        }
    }
    _size = 0;
}

size_t strsize_i::size() const {
    return _size;
}

using namespace std;

void func(const strsize & s) {
    printf("size is %ld\n", s.size());
}

void func_i(const strsize_i & s) {
    printf("size is %ld\n", s.size());
}


int main(int argc, char *argv[])
{
    puts("explicit contstructors");
    strsize s(7);
    printf("size is %ld\n", s.size());
    func(strsize(5));
    puts("---------------");
    puts("implicit constructors");
    // strsize si = <int> calls a copy constructor strsize_i(int)
    strsize_i si = 7; 
    printf("size is %ld\n", si.size());
    // func(strsize_i s) will call a copy constructor strsize_i(int)
    func_i(5);
    puts("---------------");
    puts("implicit constructors -- side effects");
    strsize_i si2 = 'x';
    printf("Size is %ld\n", si2.size());
    func_i('x');
    puts("Returns 120, which is the ordinal value of 'x'\n");
    return 0;
}

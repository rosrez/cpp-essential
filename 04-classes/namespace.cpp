#include <cstdio>
#include <string>

// We create a class in its own namespace but we 
// don't indent the definition; this is common practice.

namespace prefstring {

const std::string prefix = "(pref)";

class string {
    std::string _s;         // std:: - to refer to std namespace
    string();               // prevent default constructor by making it private
public:
    string(const std::string & s) : _s(prefix + s) {};
    const char * c_str() { return _s.c_str(); };
    operator const std::string & () { return _s; };
};

};      // namespace prefstring

std::string s1("This is a string");

// We could also say:
//
// using namespace prefstring;
//
// and then we don't need to prefix the string class
// to indicate that it is prefstring::string.
// Also, we could use a part of the namespace:
//
// using namespace prefstring::string;
//
// Again, we would have achieved the same effect for
// prefstring::string, but other names from the namespace
// would not be imported.

int main(int argc, char *argv[]) {
    // refer to prefsting namespace, and hence the string class defined therein
    prefstring::string s(s1);
    std::puts(s.c_str());
    return 0;
}

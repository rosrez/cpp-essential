#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string s1 = "This is a string";

    // size & length
    cout << "s = " + s1 << endl;
    // .size() can be used on any container
    cout << "size is same as length: " << s1.size() << endl;
    // .length() is just an alias of .size() unique to string
    cout << "size is same as length: " << s1.length() << endl;

    // concatenation
    cout << "concatenated strings: ";
    string s2 = "this is also a string";
    cout << s1 + ":" + s2 << endl;

    // compare
    cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
    cout << "copy-assign s2 = s1" << endl;
    s2 = s1;
    cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;

    string os = "other string";
    cout << "is s1 > \"" + os + "\"? " << (s1 > os ? "yes" : "no") << endl;
    cout << "is s1 < \"" + os + "\"? " << (s1 < os ? "yes" : "no") << endl;

    // insert & erase with an iterator -- similar to any other container
    s1.insert(s1.begin() + 5, 'X');
    cout << "after insert: " << s1 << endl;

    s1.erase(s1.begin() + 5);
    cout << "after erase: " << s1 << endl;

    // replace
    s1.replace(5, 2, "ain't");
    cout << "after replace: " << s1 << endl;

    // substr
    cout << "substr: " << s1.substr(5, 5) << endl;

    // find -- find substring
    size_t pos = s1.find("s");
    cout << "find first \"s\" in s1 (pos): " << pos << endl;

    // rfind -- find substring from reverse end
    pos = s1.rfind("s");
    cout << "find last \"s\" in s1 (pos): " << pos << endl;
    return 0;
}

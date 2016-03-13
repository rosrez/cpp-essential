#include <cstdio>
#include <string>
using namespace std;

// older code might have <class T> instead of
// <typename T>

template <typename T> T maxof(T a, T b) {
    return a > b ? a : b;
}

int main(int argc, char *argv[]) {

    // maxof<int> -- <int> is a template argument list.
    // We could have omitted <int> here and the example
    // would still work, because the compiler infers
    // the type based on the type of arguments.
    // However, this doesn't work well under some circumstances.
    printf("max(7,9) is: %d\n", maxof<int>(7, 9));
    printf("max(""this"", ""that"") is: %s\n", maxof<string>("this", "that").c_str());
    return 0;
}

#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    int a[] = { 1, 2, 3, 4, 5 };
    char s[] = "string";
    string ss = "STRING";

    // requires -std=gnu++11 or -std=c++11
    for (int i : a) {
        printf("%d ", i);
    }
    putchar('\n');

    // iterating over an array of chars
    for (char c : s) {
        if (c == '\0')  // our array includes the terminating null character
            break;
        putchar(c);
    }
    putchar('\n');

    // iterating over a C++ string
    for (char c : ss) {
        putchar(c);
    }
    putchar('\n');



    return 0;
}

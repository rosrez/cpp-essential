#include <iostream>     // for cout and friends
using namespace std;

int main(int argc, char *argv[])
{
    /*
     * cout overloads the bitwise left shift operator (<<)
     * to provide operations of sending to console.
     */

    cout << "Hello World!" << 2 * 7 << "another string" << endl;

    return 0;
}

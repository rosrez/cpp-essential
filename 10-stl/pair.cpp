#include <iostream>
#include <utility>      // normally, we don't need to include it
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    pair<int, int> p = { 5, 47 };
    pair<int, string> ps = { 13, "this is a string" };
    cout << "p:  first is " << p.first << ", second is " << p.second << endl;
    cout << "ps: first is " << ps.first << ", second is " << ps.second << endl;

    return 0;
}

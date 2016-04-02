#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
    list<int> li = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "size(): " << li.size() << endl;
    cout << "front(): " << li.front() << endl;
    cout << "back(): " << li.back() << endl << endl;

    cout << "push_back(47)" << endl;
    li.push_back(47);
    cout << "size: " << li.size() << endl;
    cout << "back(): " << li.back() << endl;

    // range-based for loop
    cout << "range-based for loop: " << endl;
    for (int v : li) {
        cout << v << " ";
    }
    cout << endl << endl;

    // need an iterator to insert and erase
    list<int>::iterator it1 = li.begin();
    while ((*++it1 != 5) && (it1 != li.end()));
    // found element equal to 5
    if (it1 != li.end()) {
        cout << "insert 112 before 5: " << endl;
        li.insert(it1, 112);
    }
    for (int v : li) cout << v << " ";
    cout << endl;

    while ((*++it1 != 7) && (it1 != li.end()));
    // found element equal to 7
    if (it1 != li.end()) {
        cout << "erase 7:" << endl;
        li.erase(it1);
    }
    for (int v : li) cout << v << " ";
    cout << endl;

    cout << "erase 112 to 8:" << endl;
    list<int>::iterator it2 = it1 = li.begin();
    // find 112
    while ((*++it1 != 112) && (it1 != li.end()));
    // find 8
    while ((*++it2 != 8) && (it2 != li.end()));
    // if we indeed found both numbers... erase them and everything in between
    if (it1 != li.end() && it2 != li.end()) {
        cout << *it1 << " " << *it2 << endl;
        li.erase(it1, it2);
        for (int v : li) cout << v << ".";
        cout << endl << endl;
    }
    cout << endl;

    return 0;
}

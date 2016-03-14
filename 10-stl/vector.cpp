#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "vector from initializer list: " << endl;

    // C++11 feature - initializer list
    vector<int> vi1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "size: " << vi1.size() << endl;
    cout << "front: " << vi1.front() << endl;
    cout << "back: " << vi1.back() << endl;

    // iterator
    vector<int>::iterator itbegin = vi1.begin();
    vector<int>::iterator itend = vi1.end();
    // C++11: use auto to avoid repeating the vector<int> type
    for (auto it = itbegin, it < itend; ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    cout << "element at 5: " << vi1[5] << endl;
    cout << "element at 5: " << vi1.at(5) << endl;

    cout << "range-based for loop over vector:" << endl;
    for (int & i : vi1) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "insert 42 at begin + 5: " << endl;
    vi1.insert(vi1.begin() + 5, 42);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;

    cout << "erase at begin + 5: " << endl;
    vi1.erase(vi1.begin() + 5);
    cout << "size: " << vi.size() << endl;
    cout << "vi1[5]: " << vi[5] << endl;

    cout << "push back 47: " << endl;
    vi1.push_back(47);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi.back() << endl;

    // vector of strings
    cout << "vector of stings:" << endl;
    vector<string> vs = {"one", "two", "three", "four", "five"};
    for (string &v : vs) {
        cout << v << endl;
    }

    return 0;
}

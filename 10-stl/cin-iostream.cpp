#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    // cout is the output class from iostream
    cout << "cin input stream demo";

    // word-oriented input from cin:
    // the right-shift operator will input just a single word from cin
    string istr;
    cout << "Prompt (1 - a single word): ";
    cin >> istr;        // input one word at a time
    cout << "Input: " << istr << endl;

    // line-oriented input from cin 
    char buf[128];
    cout << "Prompt (2 - a line of text): ";
    cin.getline(buf, sizeof(buf));        // input a line
    cout << "Input: " << buf << endl;

    return 0;
}

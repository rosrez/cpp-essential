#include <iostream>
#include <iomanip>
using namespace std;

// Note: endl is also a manipulator. Apart from appending a newline
// to the output it also flushes the output.

int main(int argc, char *argv[]) {
    // cout is the output class from iostream
    cout << "iostream demo";

    // integer formatting
    int i1 = 42;
    int i2 = 127;
    int i3 = 5555;
    cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << endl;
    // 'hex' manipulator will convert output to hexadecimal: 2a 7f 15b3
    cout << "hex: " << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    // showbase will turn on displaying base, e.g.:  0x2a 0x7f 0x15b3
    cout << "hex with showbase: " << showbase << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    // the following will produce this: 052 0177 012663
    // octal values are prepended with zeroes here because the previous showbase is still in effect
    cout << "octal with showbase: " << oct << i1 << ' ' << i2 << ' ' << i3 << endl;
    // noshobase will turn off displaying the base for this output:
    cout << "default: " << noshowbase << dec << i1 << ' ' << i2 << ' ' << i3 << endl;

    // floating point formatting options
    double d1, d2, d3;
    d1 = 3.1415926534;
    d2 = 1234.5;
    d3 = 4.2e-10;
    cout << "default: " << d1 << ' ' << d2 << ' ' << ' ' << endl;
    // fixed: 3.141593 1234.500000 0.000000 -- defaults to 6 decimal places
    cout << "fixed: " << fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // scientific: 3.141593e+00 1.234500e+03 4.200000e-10 
    cout << "scientific: " << scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // fixed (3): 3.142 1234.500 0.000
    cout << "fixed (3): " << setprecision(3) << fixed <<  d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // fixed (7): 3.1415927 1234.5000000 0.0000000
    cout << "fixed (7): " << setprecision(7) << scientific << fixed <<  d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // resets the defaults
    cout.unsetf(ios_base::floatfield);
    cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;

    // string formatting options
    string s1 = "This is a string.";
    string s2 = "This is a much longer string.";
    string s3 = "Today's news: Big Light in Sky Slated to Appear in East";

    // regular output: each string on a separate line
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    // set width to 64 characters and right-align
    cout << setw(64) << right << s1 << endl;
    cout << setw(64) << right << s2 << endl;
    cout << setw(64) << right << s3 << endl;

    // same as before, but fills the space on the left with -
    cout << setfill('-') << setw(64) << right << s1 << endl;
    cout << setfill('-') << setw(64) << right << s2 << endl;
    // back to the original left alignment
    cout << left << s3 << endl;

    return 0;
}

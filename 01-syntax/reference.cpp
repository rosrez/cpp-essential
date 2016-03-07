#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
    int x = 7;

    // When you define a reference, you must initialise it
    // Once a reference is initialised, it remains attached
    // to the same variable throughout its life.

    int &y = x;     // reference
    int *ip = &x;   // pointer

    printf("The value of x is %d\n", x);

    // Using a reference doesn't involve any extra characters,
    // i.e. you place a reference in expressions just as you
    // would a normal variable.
    
    printf("The value of y is %d (reference)\n", y);
    printf("The value of *ip is %d\n", *ip);

    // Let's assign to x and see that the result is visible
    // through the other variables.
    x = 42;
    printf("The value of x is %d\n", x);
    printf("The value of y is %d (reference)\n", y);
    printf("The value of *ip is %d\n", *ip);


    // Let's assign to a reference (y) and see that the result is visible
    // through the other variables.
    y = 73;
    printf("The value of x is %d\n", x);
    printf("The value of y is %d (reference)\n", y);
    printf("The value of *ip is %d\n", *ip);

    // Assigning another variable to a reference (y), does not change
    // what the reference is attached to, it just modifies the underlying
    // value (x's, in this case)
    int z = 140;
    ip = &z;        // ip now holds a different address, that of z 
    y = z;         // y's address is the same, only the contents are different
    printf("The value of x is %d\n", x);
    printf("The value of y is %d (reference)\n", y);
    printf("The value of *ip is %d\n", *ip);



    return 0;
}

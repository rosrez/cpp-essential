#include <cstdio>
using namespace std;

// Functor demonstration
// Functor is a simple class that overrides the () operator
// and can therefore mimic a function.

// This is a 'multiplicator' class. A call to MultBy()
// multiplies the argument n times
class MultBy {
    int mult;
    MultBy();
public:
    MultBy(int n) : mult(n) {}
    int operator() (int n) const { return mult * n; }
};

int main(int argc, char *argv[]) {
    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);

    printf("times4(5) is %d\n", times4(5));
    printf("times4(15) is %d\n", times4(15));
    printf("times10(5) is %d\n", times10(5));
    printf("times10(5) is %d\n", times10(5));
    printf("times15(5) is %d\n", times15(5));
    printf("times15(15) is %d\n", times15(15));
    return 0;
}

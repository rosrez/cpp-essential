#include <cstdio>
using namespace std;

void func()
{
    puts("This is func()");
}

int main(int argc, char *argv[])
{
    void (*fp)() = func;        // would also work with ... = &func
    puts("This is main");
    fp();                       // would also work as (*fp)();
    return 0;
}

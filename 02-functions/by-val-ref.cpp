#include <cstdio>
using namespace std;

void func_val(int i)
{
    printf("value assigned inside func_val(): %d\n", ++i);
}

void func_ref(int & i)
{
    printf("value assigned inside func_ref(): %d\n", ++i);
} 

int main (int argc, char *argv[])
{
    int x = 42;
    printf("initial value: %d\n", x);
    func_val(x);
    printf("after call to func_val(): %d\n", x);
    func_ref(x);
    printf("after call to func_ref(): %d\n", x);
}

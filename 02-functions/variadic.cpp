#include <cstdio>
#include <cstdarg>      // needed to support variadic arguments

// first argument is int count of remaining args
// ... remaining args are doubles for average
double average(const int count, ...) {
    va_list ap;     // argument pointer - declare a list of arguments
    int i;
    double total = 0.0;

    va_start(ap, count);    // 'count' is the last fixed argument from function signature; see above
    for (i = 0; i < count; ++i) {
        total += va_arg(ap, double);    // extract argument, provide type
    }
    va_end(ap);             // terminate the variadic argument list
    return total / count;
}

// works like printf, format plus args
int message(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap); // vfprintf() takes the va_list ap as a parameter
    puts("");
    va_end(ap);
    return rc;
}

int main(int argc, char *argv[]) {
    message("This is a message");
    message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
    return 0;
}

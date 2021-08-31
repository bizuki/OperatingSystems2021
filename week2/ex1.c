#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (void) {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("integer: size = %lu, value = %d\n", sizeof a, a);
    printf("float: size = %lu, value = %f\n", sizeof b, b);
    printf("double: size = %lu, value = %lf\n", sizeof c, c);
}

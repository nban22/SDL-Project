#include <stdio.h>

int main() {
    unsigned int a, b, c;
    scanf("%u %u %u", &a, &b, &c);
    unsigned int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("%u", max);
    return 0;
}
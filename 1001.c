#include <stdio.h>
#include <math.h>

int test(x) {
    return (int)sqrt(x);
}

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        printf("%d\n\n", (1 + a) * a / 2);
    }
    printf("%d\n", test(2147483647));
    return 0;
}


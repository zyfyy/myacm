#include <stdio.h>

int sum(int x) {
    int i, sum = 0;
    for (i = 1; i <= x; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        printf("%d\n\n", sum(a));
    }
    return 0;
}

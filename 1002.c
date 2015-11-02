#include <string.h>
#include <stdio.h>

#define MAX 1001

void sum(const char *x, const char *y) {
    char z[MAX];
    int i, lx = strlen(x) - 1, ly = strlen(y) - 1, up = 0;
    for (i = 0; lx >= 0 || ly >= 0; ++i, --lx, --ly) {
        if (lx >= 0 && ly >= 0) {
            z[i] = x[lx] + y[ly] - '0' + up;
        } else if (lx >= 0 && ly < 0) {
            z[i] = x[lx] + up;
        } else if (lx < 0 && ly >= 0) {
            z[i] = y[ly] + up;
        }
        up = 0;
        if (z[i]  > '9') {
            up = 1;
            z[i] = z[i] - 10;
        }
    }
    if (up == 1) {
        printf("%d", up);
    }
    while (i--) {
        printf("%c", z[i]);
    }
    printf("\n");
}

int main() {
    int l, m = 1;
    char x[MAX], y[MAX];

    scanf("%d", &l);
    while (l--) {
        scanf("%s %s", x, y);

        printf("Case %d:\n%s + %s = ", m++, x, y);
        sum(x, y);
        if (l != 0) {
            printf("\n");
        }
    }
    return 0;
}

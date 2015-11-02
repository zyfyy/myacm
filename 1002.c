#include <string.h>
#include <stdio.h>

#define MAX 1001

char* sum(char *x, const char *y) {
    int i, j, k, tmp, up = 0;

    for (i = strlen(x), j = strlen(y); j > 0; --i, --j){
        tmp = x[i-1] + y[j-1] - 96 + up;

        if (tmp >= 10) {
            x[i-1] = tmp + 48 - 10;
            up = 1;
        } else {
            x[i-1] = tmp + 48;
            up = 0;
        }
    }

    while (up == 1 && j == 0 && i >= 0) {
        if (i == 0) {
            for (k = strlen(x); k > 0; --k) {
                x[k] = x[k-1];
            }
            x[0] = up + 48;
            up = 0;
        } else {
            if (x[i-1] + up - 48 < 10) {
                x[i-1] = x[i-1] + up;
                up = 0;
            } else {
                x[i-1] = '0';
            }
            --i;
        }
    }

    return x;
}

int main() {
    int l, m;
    char x[MAX], y[MAX];

    while(scanf("%d", &l) != EOF) {
        m = 1;
        while (m <= l) {
            scanf("%s %s", x, y);
            unsigned long i = strlen(x);
            unsigned long j = strlen(y);

            printf("Case %d\n%s + %s = ", m++, x, y);
            if (i >= j) {
                printf("%s\n", sum(x, y));
            } else {
                printf("%s\n", sum(y, x));
            }
            if (m <= l) {
                printf("\n");
            }
        }
    };
    return 0;
}

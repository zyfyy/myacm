#include "stdio.h"
#include "string.h"
int main()
{
    int a[1010] = {0}, b[1010] = {0}, c[1010] = {0};
    int i, d, l1, l2, T, tem;
    char s1[1010], s2[1010];
    while(scanf("%d", &T) != EOF)
    {
        tem = 1;
        while(tem <= T)
        {
            scanf("%s%s", s1, s2);
            l1 = strlen(s1);
            l2 = strlen(s2);
            for(i = 0; i < l1; i++)
            {
                a[l1 - 1 - i] = s1[i] - '0';
            }
            for(i = 0; i < l2; i++)
            {
                b[l2 - 1 - i] = s2[i] - '0';
            }
            d = 0;
            for(i = 0; (i <= l1 || i <= l2); i++)
            {
                c[i] = (a[i] + b[i] + d) % 10;
                d = (a[i] + b[i] + d) > 9 ? 1 : 0;
            }
            while(c[i] == 0)
            {
                i--;
            }
            printf("Case %d:\n", tem++);
            printf("%s + %s = ", s1, s2);
            while(i >= 0)
            {
                printf("%d", c[i]);
                i--;
            }
            printf("\n");
            if(tem <= T)  printf("\n");
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(c, 0, sizeof(c));
        }
    }
    return 0;
}

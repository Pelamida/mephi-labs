#include <stdio.h>

int main()
{
    int m, n = 1, k = 0;
    scanf("%d", &m);
    while (n<=m) {
        n *= 3;
        ++k;
    }
    printf("%d\n", k);
    
    return 0;
}

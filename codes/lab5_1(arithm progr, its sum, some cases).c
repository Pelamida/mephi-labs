#include <stdio.h>

float progr(float a, float d, int n, float *an, float *sn) {
    if (n<=0) return 1;
    *an = a + (n-1)*d;
    *sn = n * (a + *an)/2;
    if ((*an) * a < 0) return 2;
    if (d==0) return 3;
    return 0;
}

int main()
{
    float a, d;
    int n;
    float an, sn;
    scanf("%f %f %d", &a, &d, &n);
    int sign = progr(a, d, n, &an, &sn);
    if (sign != 1) printf("%d\n%f\n%f\n", sign, an, sn);
    else printf("%d\n", sign);
    return 0;
}


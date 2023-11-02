#include <math.h>
#include <stdio.h>
#include <limits.h>
int main() {
    long int sum=0, ans, val;
    int k, n=0, flag=1;
    char sign;
    float m;
    scanf("%d", &k);

    if (k==1) printf("error\n");
    else {
        while(1) {
            n++;
            for(int i=1; i<2*k; i+=2) {
                if (i>pow(LONG_MAX, (float) 1/n)) {
                    sign='*';
                    flag=0;
                    break;
                }
                val = pow(i, n);
                
                if (sum <= LONG_MAX-val) sum += val;
                else {
                    sign='+';
                    flag=0;
                    break;
                }
            }
            if (flag) {
                ans = sum;
                sum = 0;
            }
            else {
                printf("%ld\n", ans);
                printf("%d\n", n-1);
                printf("%c\n", sign);
                break;
            }
        }
    }
    return 0;
}

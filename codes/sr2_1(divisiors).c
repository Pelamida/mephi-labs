#include <stdio.h>
int main()
{
    int i, j, num, num_max, count, c_min, dividors, flag1, flag2;
    flag1 = 1;
    num_max = 400;
    c_min = 400;
    for (i = 400; i <= 430; ++i) {
        num = i;
        if (flag1) {
            printf("%d", i);
            flag1 = 0;
        }
        else {
            printf("\n%d", i);
        }
        
        flag2 = 1;
        count = 0;
        dividors = 0;
        for (j = 2; j < i; ++j) {
            if (i % j == 0) {
                if (dividors == 0) {
                    if (flag2) {
                        printf("%5d", j);
                        flag2 = 0;
                    }
                    else
                        printf(",\n%8d", j);
                }
                else
                    printf(",%3d", j);
                dividors++;
                if (dividors == 4){
                    dividors = 0;
                }
                count++;
            }
        }
        if (dividors == 0)
            if (flag2)
                printf("%23d", count);
            else
                printf("%6d", count);
        if (dividors == 1)
            printf("%18d", count);
        if (dividors == 2)
            printf("%14d", count);
        if (dividors == 3)
            printf("%16d", count);
        
        if ((count<=c_min)&&(count != 0)) {
            num_max = num;
            c_min = count;
        }

    }
    printf("\n\n%d\n", num_max);
    return 0;
}

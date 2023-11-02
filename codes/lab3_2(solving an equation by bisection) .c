#include <stdio.h>

float func(double x) {
	float value = 2*x*x*x - 9*x*x - 60*x + 1;
	return value;
	}

int main()
{
    float x, a=-2, b=2, c, x0=2e-8;
    while (b-a>x0) {
        c = (a+b)/2;
        if ((func(a)>=0)&&(func(c)<=0)) b = c;
        else a = c;
    }
    x = (a+b)/2;
    printf("%.8f\n", x);
    return 0;
}

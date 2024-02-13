#include <stdio.h>
#include <math.h>
#include <limits.h>
long int longmax=23234687; //2145555555, выраженное в десятичной сс 

long int NexToDec(long int number)
{
    long int decNum = 0;
    int power = 0;
    while (number != 0)	 {
        int rem = number % 10;
        decNum += rem * pow(6, power);
        number /= 10;
        power++;
    }
    return decNum;
}

long int DecToTern(long int decimal)
{
    int ternary[32], i=0, j, k;
    while (decimal > 2) {
        ternary[i] = decimal % 3;
        decimal = decimal / 3;
        i++;
    }
    ternary[i] = decimal;
    
    for (k=0; k<=i; k++) printf("%d ", ternary[k]);
    printf("\n");
    long int power = 1;
    long int value = 0;
    for (int j=0; j<=i; j++) {
        printf("%d: %ld\n", j, value);
        value += ternary[j]*power;
        power *= 10;
    }
    return value;
}

long int sum(long int x, long int y, long int *ans) {
    if (x > longmax-y || x < -longmax-y) return 1;
    else *ans = x+y;
    return 0;
}

long int sub(long int x, long int y, long int *ans) {
    if (x < y-longmax || x > longmax+y) return 2;
    else *ans = x-y;
    return 0;
}

long int prod(long int x, long int y, long int *ans) {
    if (x > longmax/y || x < -longmax/y) return 3;
    *ans = x*y;
    return 0;
}

long int power(long int x, long int y, long int *ans) {
    long int val = 1;
    if (x==0) return 4;
    for (int i=1; i<=y; i++) {
    	if (val > longmax/x || val < -longmax/x) return 4;
    	val *= x;
    }
    *ans = val;
    return 0;
}

long int divis(long int x, long int y, long int *ans) {
    if (y==0) return 5;
    *ans = x/y;
    return 0;
}

long int mod(long int x, long int y, long int *ans) {
    if (y==0) return 6;
    *ans = x%y;
    return 0;
}

long int expression1(long int a, long int b) {
	long int x, y, ans;
	int error = power(a, 2, &x);
	if (error!=0) { //x = a^2
        printf("!%d", error);
        return longmax+1;
	}
    error = prod(x, b, &x);
    if (error!=0) { //x = a^2*b
        printf("!%d", error);
        return longmax+1;
    }
    error = sub(a, b, &y);
    if (error!=0) { //y = a-b
        printf("!%d", error);
        return longmax+1;
    }
    error = prod(a, y, &y);
    if (error!=0) { //y = a(a-b)
        printf("!%d", error);
        return longmax+1;
    }
    error = sub(x, y, &ans);
    if (error!=0) { //ans = a^2*b-a(a-b)
    	printf("!%d", error);
    	return longmax+1;
    }
    error = sum(ans, a, &ans);
    if (error!=0) { //ans = a^2*b-a(a-b)+a
    	printf("!%d", error);
    	return longmax+1;
    }
    //printf("%ld", ans);
    return ans;
}

int main()
{
    // long int number = -125;
    // long int decimalNumber = NexToDec(number);
    
    long int a, b, c, x, y, z, ans1, ans2, ans3;
    // int error = 0;
    
    scanf("%ld %ld %ld", &a, &b, &c);
    // a = NexToDec(a);
    // b = NexToDec(b);
    // c = NexToDec(c);
    printf("%ld", expression1(a,b));
    return 0;
}

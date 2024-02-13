#include <stdio.h>

long int fib(int n, long int cash[]) {
	if (n <= 0) return -1;
    if (cash[n]) return cash[n];
    long int ans = fib(n-1, cash) + fib(n-2, cash);
    cash[n] = ans;
    return ans;
}

int print_str(int level, int i, long int cash[]) {
    if (i<1) return 0;
    if (i<=2) printf("%5d               i=%d  return 1; (f=1)\n", level, i);
    else {	
    	long int a = fib(i-1, cash);
    	long int b = fib(i-2, cash); 
    	printf("%5d      i=%d  f(%d)+f(%d)   \treturn %ld+%ld; (f=%ld)\n", level, i, i-1, i-2, a, b, a+b);
    	}
    return 0;
}

int main() {
    int n, level = 1, a, b;
	
	long int cash[92];
	for (int i=0; i<92; i++) cash[i]=0;
	cash[1] = 1;
	cash[2] = 1;
    scanf("%d", &n);
    
    if (n>92) {
        printf("!");
        return 0;
    }
    
    long int ans = fib(n, cash);
    
    printf("trace lev  recursive descent    recursive return\n");
    printf("    0     input: n = %d  f(%d)  output: %ld\n", n, n, ans);
    
    int k = n;
    while(k>1) {
        print_str(level, k, cash);
        k--;
        level++;
    }

    printf("                    i=1  return 1; (f=1)\n");
    printf("%ld\n", ans);
    
    return 0;
}

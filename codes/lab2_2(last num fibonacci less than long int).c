#include <stdio.h>
#include <limits.h>

int main()
{
    int k, i;
    long int n, a=1, b=1;
    scanf("%d", &k);
    for (i=1; i<=k; ++i) {
        if (a > LONG_MAX - b) break;
        
    	if (i==1 || i==2)
    	    printf("  %d  1\n", i);
    	else {
    	    n = a + b;
    	    if (i/10) printf(" %d  %ld\n", i, n);
    	    else printf("  %d  %ld\n", i, n);
    	    a = b;
    	    b = n;
    	}

    }
    
    printf("\n");
    while (1) {
        
        n = a + b;
        if (n > LONG_MAX - b) break;
        a = b;
        b = n;
        i += 1;
    }
    
    printf(" %d  %ld\n", i-2, a);
    printf(" %d  %ld\n", i-1, b);
    printf(" %d  %ld\n", i, n);
    
    return 0;
}

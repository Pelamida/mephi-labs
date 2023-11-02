#include <stdio.h>
#include <limits.h>

int count = 0, err;

unsigned long int maxi(unsigned long int n, unsigned long int m) {
// 	printf("now I in maxi\n");
	if (m>n) return m;
	else return n;
}

unsigned long int calcul(unsigned long int x, unsigned long int y) {
	   // printf("now I in calcul\n");
	if (x<=ULONG_MAX-y) {
		err = -2;
		return -1;
	}
	return x + y;
}

unsigned long int F(unsigned long int n, unsigned long int m) {
	unsigned long int ans;
	count++;
	if (count>100) {
		err = -1;
		return -1;
	}
    if ((n+m)%2==0) return maxi(n,m);
    int k = (n+m+1)/2;
    // printf("%d\n", count);
    ans = calcul(F(k, m), F(n, k));
    return ans;
}

int main()
{
	unsigned long int n, m, val;
    scanf("%lu %lu", &n, &m);
    val = F(n, m);
    if (err == -1) printf("endless\n");
    else if (err == -2) printf("overflow\n");
    else printf("%lu\n", val);

    return 0;
}

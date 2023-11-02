#include <stdio.h>

int main(void)
{
	int x, x2, prod, ans;
	scanf("%d", &x);
	x2 = (x * x);
	if (x2 / 1000)
		prod = (x2 / 1000) * ((x2 / 100) % 10) * ((x2 / 10) % 10) * (x2 % 10);
	else
		prod = ((x2 / 100) % 10) * ((x2 / 10) % 10) * (x2 % 10);
	
	ans = x2 % prod;
	printf("%d\n", ans);

	return 0;
}

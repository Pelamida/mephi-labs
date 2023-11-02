#include <stdio.h>

int main(void)
{
	int x1, x2, x3, tmp;
	
	scanf("%d %d %d", &x1, &x2, &x3);
	
	if (x2 < x3) {
		tmp = x2;
		x2 = x3;
		x3 = tmp;
	}
		
	if (x1 < x2) {
	    tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
		
	if (x2 < x3) {
		tmp = x2;
		x2 = x3;
		x3 = tmp;
	}

	
	if (x1 == x2 && x1 == x3)
		printf("%d=%d=%d\n", x1, x2, x3);
	else if (x1 == x2)
		printf("%d=%d>%d\n", x1, x2, x3);
	else if (x2 == x3)
		printf("%d=%d<%d\n", x2, x3, x1);
	else
		printf("%d\n", x2);
	
	return 0;
}

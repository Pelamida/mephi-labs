#include <stdio.h>

int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	if ((x*x + y*y < 90000) && (y > 150) && (y > x) && (y > -x))
		printf("inside\n");
	else if ((x<300 && x>-300) && (y>-300 && y<0) && (x*x + y*y > 90000))
		printf("inside\n");
	else
		printf("outside\n");

	return 0;
}

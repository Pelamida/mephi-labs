#include <math.h>
#include <stdio.h>

int main()
{
    double sum=0.0, x0=1e-8, s = M_PI/4, delta=1.0;
    int n=1;
    while (delta>x0) {
    	sum += (double) pow(-1, n+1)/((double) 2*n-1);
    	n++;
        delta = fabs(s-sum);
    } 
    printf("%.8f\n%.8f\n%.8f\n%d\n", s, sum, delta, n-1);
    return 0;
}

//c Кохеном
#include <math.h>
#include <stdio.h>

int main()
{
    double sum=0.0, x0=1e-8, s = M_PI/4, delta=1.0;
    double f, fcor, Scor, cor, S;
    int n=1;
    while (delta>x0) {
        cor = 0.0; Scor = 0.0;
  	    f = (double) pow(-1, n+1)/((double) 2*n-1);
  	    fcor = f - cor;
  	    Scor = sum + fcor;
  	    cor = (Scor - sum) - fcor;
  	    sum = Scor;
        
    	n++;
        delta = fabs(s-sum);
    } 
    printf("%.8f\n%.8f\n%.8f\n%d\n", s, sum, delta, n-1);
    return 0;
}


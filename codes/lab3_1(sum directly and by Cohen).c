#include <stdio.h>
#include <math.h>

double value(int n) {
	double val;
	double sq = sqrt(n);
	double cub = pow(n, 3);
	val = sqrt((1+pow(cos(n), 2)+sq+3*cub)/(3+sq+cub));
	return val;
	}

int main()
{
    int n = 20000000, i, str;
    double sum = 0, f;
    double S = 0.0, cor = 0.0, Scor = 0.0, fcor, delta;
    for (str=20000000; str<=200000000; str += n) {
        for (i=str-n+1; i<=str; i++) {
            f = value(i);
    	    sum += f;
    	
  	        fcor = f - cor;
  	        Scor = S + fcor;
  	        cor = (Scor - S) - fcor;
  	        S = Scor;
  	    
  	        delta = sum - Scor;
        }
        printf("%9d %17.4f %17.4f %9.4f\n", str, sum, Scor, delta);
    }
    return 0;
}

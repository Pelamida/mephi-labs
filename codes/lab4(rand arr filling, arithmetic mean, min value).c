#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n=40, a, i, min_val, max_val;
    // scanf("%d", &min_val);
    // scanf("%d", &max_val);
    int arr[n], sum=0, amin=10e6, count=0;
    float m;
  
    //srand(time(0));
    for (i = 0; i < n; i++) {
        // arr[i] = rand() % (max_val - min_val + 1) + min_val;
        // printf("%d\t%d\n", i, arr[i]);
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &a);
    
    for (i = 0; i < n; i++) {
    	if (arr[i] > a) {
    		sum += arr[i];
    		count++;
    	}
    }
    m = (float)sum / count;
    printf("%.4f\n", m);
        
    sum = 0;
    count = 0;
    for (i = 0; i < n; i++) {
    	if ((float)arr[i] > m) {
    		sum += arr[i];
			if (arr[i] < amin) {
				amin = arr[i]; 
				count=1;
			}
			else if (arr[i] == amin) count++;
    	}
    }
	
	printf("%d\n", sum);
    printf("%d %d\n", amin, count);
    return 0;
}

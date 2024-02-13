#include <stdio.h>
int comparison1 = 0; //сравнений
int comparison2 = 0;
int assignments1 = 0; //присваиваний
int assignments2 = 0;

void printer(int N, int arr[]) {
    printf("\n\n");
    for (int i = 1; i <= N; i++) printf("%3d", i);
    printf("\n");
	for (int i = 0; i < N; i++) printf("%3d", arr[i]);
}

void InsertionSort(int n, int a[])
{
	int i, j, temp;
	for (i=1; i < n; i++) {
	    temp = a[i];
    	for (j = 0; j < i; j++) {
    	    comparison1++;
        	if (a[j] > temp && i!=j) break;
    	}
    	
    	for (int k=i; k>=j; k--) {
    	    a[k]=a[k-1];
    	    assignments1++;
    	}
        a[j] = temp;
        assignments1++;
        printer(n, a);
	}
}

void BubbleSort(int n, int a[])
{
	int i, j, temp;
    for(i = 0 ; i < n-1; i++) { 
        for(j = 0 ; j < n-i-1 ; j++) {
            comparison2++;
            if(a[j] > a[j+1]) {           
              int tmp = a[j];
              a[j] = a[j+1] ;
              a[j+1] = tmp; 
              assignments2 += 3;
           }
        }
        printer(n, a);
    }
}

// 6
// 3 1 9 2 7 5
int main()
{
    int N;
    scanf("%d", &N);
    int arr1[N], arr2[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr1[i]);
    for (int i = 0; i<N; i++) arr2[i] = arr1[i];
    
    for (int i = 1; i <= N; i++) printf("%3d", i);
    printf("\n");
    for (int i = 0; i < N; i++) printf("%3d", arr1[i]);
    
    InsertionSort(N, arr1);
    printf("\n%d %d", assignments1, comparison1);
    BubbleSort(N, arr2);
    printf("\n%d %d\n", assignments2, comparison2);
    // printer(N, arr2);
    return 0;
}

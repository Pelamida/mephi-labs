#include <stdio.h>

int assignments = 0; //присваиваний
int comparisons = 0; //сравнений

void swap(int *x, int *y) {
 	int temp; 
 	temp=*x;
 	*x=*y;
 	*y=temp;
 	assignments += 3;
}

void printer(int N, int arr[]) {
    printf("\n\n");
    for (int i = 1; i <= N; i++) printf("%3d", i);
    printf("\n");
	for (int i = 0; i < N; i++) printf("%3d", arr[i]);
}

void QuickSort(int first, int last, int A[], int n) {
    int pivot; /*опорное значение*/
    int l,r; /*левый и правый счетчики*/
    l=first; r=last;
    pivot=A[(l+r)/2]; /*определение опорного значения*/
    while (l<=r) {
 	    comparisons+=2;
 	    while (A[l]<pivot) {
 		    l++;
 		    comparisons++;
 		    assignments++;
 	    }
 	    while (A[r]>pivot) {
 		    r--;
 		    comparisons++;
 		    assignments++;
 	    }
 	    if (l<=r) {
 		    if (l!=r) {
 	    	    swap(&A[l],&A[r]); /*перестановка двух элементов*/
 		        printer(n, A);
 		    }
 		    l++;
 		    r--;
 		    assignments++;
 	    }
    } /*Рекурсивная сортировка:*/
    if (first<r) QuickSort(first, r, A, n); /*левого участка */
    if (l<last) QuickSort(l, last, A, n); /*правого участка*/
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	
	for (int i = 1; i <= n; i++) printf("%3d", i);
    printf("\n");
	for (int i = 0; i < n; i++) printf("%3d", A[i]);
	
	QuickSort(0, n-1, A, n);
	if (assignments % 10) printf("\n\n%d %d\n", assignments, comparisons);
	else printf("\n\n%d  %d\n", assignments, comparisons);
	return 0;
}
/*
7
5 9 3 7 4 1 2
*/

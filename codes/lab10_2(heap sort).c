#include <stdio.h>

int assignments = 0; //присваиваний
int comparisons = 0; //сравнений

void swap(int *x, int *y) {
 	int temp; 
 	temp=*x;
 	*x=*y;
 	*y=temp;
}

void printer(int N, int arr[]) {
    printf("\n\n");
    for (int i = 1; i <= N; i++) printf("%3d", i);
    printf("\n");
	for (int i = 0; i < N; i++) printf("%3d", arr[i]);
}

void TreeRebuild(int r, int q, int A[], int n) {
 	int v, i, j, pp;
 	i=r; 	/*индекс рассматриваемого элемента*/
 	v=A[i]; /*рассматриваемый элемент*/
 	j=2*i+1;/*индекс элемента, с которым проводится сравнение*/
 	pp=0; 	/*предположение, что не найдено место в пирамиде*/
 	while (j<=q && !pp) {
 		comparisons++;
 		if (j<q) {
 			comparisons++;
 			if (A[j]>A[j+1]) /*сравнение с меньшим элементом*/
 				j++;
 		}
 		if (v<=A[j]) {
 			pp=1; /*элемент стоит на своем месте*/
 		}
 		else {
 			A[i]=A[j]; /*перестановка элемента*/
 			assignments++;
 			i=j;
 			j=2*i+1; /*прохождение дальше по пирамиде*/
 		}
 	}
 	A[i]=v;
 	assignments++;
}

void TreeSort(int A[], int n) {
 	int k,i;
 	k=n/2; /*эта часть массива является пирамидой*/
 	for (i=k-1; i>=0; i--)
 		TreeRebuild(i,n-1,A,n); /*построение пирамиды (только один раз)*/
 		printer(n, A);
 	for (i=n-1; i>=1; i--) {
 		swap(&A[0],&A[i]); /*перестановка 0-го и i-го элементов*/
 		assignments += 3;
 		printer(n, A);
 		TreeRebuild(0,i-1,A,n); /* «проталкивание» i-го элемента*/
 	}
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	TreeSort(A, n);
	printf("\n\n%d %d\n", assignments, comparisons);
	return 0;
}
/*
7
5 9 3 7 4 1 2
*/

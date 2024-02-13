#include <stdio.h>
#include <limits.h>

void fill_arr(int m[], int size, int a, int b) {
	int i;
	for (i=0; i<size; i++) m[i] = a + i*b;
}

void print(int m[], int *first, int *last) {
	int i;
 	for (i=first-m; i<=last-m; i++) printf("%5d", i+1);
 	printf("\n");
	for (i=first-m; i<=last-m; i++) printf("%5d", m[i]);
	printf("\n");
}

void swap(int m1[], int m2[], int k, int size2) {
    int i, x;
    for (i=0; i<k; i++) {
        x = m1[i];
        m1[i] = m2[size2-k+i];
        m2[size2-k+i] = x;
    }
}

int main() {
	int a1, b1, i, a2, b2, k;
	int m1[10], m2[12];
    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    scanf("%d", &k);
    fill_arr(m1, 10, a1, b1);
    fill_arr(m2, 12, a2, b2);
    print(m1, m1, m1+9);
    printf("\n");
    print(m2, m2, m2+11);
    printf("\n");
    
    swap(m1, m2, k, 12);
    // print(m1, m1, m1+9);
    // printf("\n");
    // print(m2, m2, m2+11);
    // printf("\n");
    
    swap(m2, m1, k, 10);
    //print(m1, m1, m1+9);
    //printf("\n");
    //print(m2, m2, m2+11);
    //printf("\n");
    
    swap(m2, m2, k, 12);
    print(m1, m1, m1+9);
    printf("\n");
    print(m2, m2, m2+11);

    return 0;
}

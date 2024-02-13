#include <stdio.h>
#include <stdlib.h>

void InsertElement(int* arr, int* n, int a, int k) {
    (*n)++;
    int* newArr = (int*)realloc(arr, (*n) * sizeof(int));
    if (newArr == NULL) return;

    arr = newArr;
    for (int i=*n-1; i>k; i--) arr[i] = arr[i-1];
    
    arr[k] = a;
}

void SwapElements(int* arr, int n, int i) {
    if (i>=0 && i<n) {
        int temp = arr[n-1];
        arr[n-1] = arr[i];
        arr[i] = temp;
    }
} 

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    
    // for (int i=0; i<n; i++) arr[i] = rand() % 26 + 5;
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    int a, k, j;
    scanf("%d %d", &a, &k);
    scanf("%d", &j);
    
    for (int i=1; i<=n; i++) printf("%3d", i);
    printf("\n");
    for (int i=0; i<n; i++) printf("%3d", arr[i]);
    printf("\n\n");
    
    InsertElement(arr, &n, a, k-1);
    SwapElements(arr, n, j-1);
    
    for (int i=1; i<=n; i++) printf("%3d", i);
    printf("\n");
    for (int i=0; i<n; i++) printf("%3d", arr[i]);
    printf("\n");
    
    free(arr);
    return 0;
}

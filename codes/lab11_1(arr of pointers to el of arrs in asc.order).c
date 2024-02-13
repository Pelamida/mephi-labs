#include <stdio.h>
#include <limits.h>

void printer_point(int **pointers, int size) {
    for (int i = 1; i <= size; i++) printf("%3d", i);
    printf("\n");
    for (int i = 0; i < size; i++) printf("%3d", *pointers[i]);
    printf("\n\n");
}

void printer(int arr[], int n) {
    for (int i = 1; i <= n; i++) printf("%3d", i);
    printf("\n");
	for (int i = 0; i < n; i++) printf("%3d", arr[i]);
	printf("\n\n");
}

int min_el(int arr[], int size, int last_imin, int used[]) {
    int minel = INT_MAX, imin;
    for (int i=0; i<size; i++) 
        if (arr[i] < minel && arr[i] >= arr[last_imin] && !used[i]) {
            minel = arr[i];
            imin = i;
        }
    used[imin] = 1;
    return imin;
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int arr1[n1], used_index[n1];
    for (int i = 0; i < n1; i++) { scanf("%d", &arr1[i]); used_index[i] = 0; }

    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &arr2[i]);
    
    int n = n1 + n2;
    int *pointers[n];

    int minel = INT_MAX, imin1;
    for (int i=0; i<n1; i++) 
        if (arr1[i] < minel) {
            minel = arr1[i];
            imin1 = i;
        }
    used_index[imin1] = 1;
    
    int i = n2-1, j = 0, k = 0;
    while (i >= 0 && j <= n1) {
        if (arr2[i] <= arr1[imin1]) {
            pointers[k] = &arr2[i];
            k++;
            i--;
        }
        else {
            pointers[k] = &arr1[imin1];
            k++;
            j++;
            imin1 = min_el(arr1, n1, imin1, used_index);
        }
    }
    while (i >= 0) pointers[k++] = &arr2[i--];
    while (j <= n1) {
        pointers[k] = &arr1[imin1];
        imin1 = min_el(arr1, n1, imin1, used_index);
        k++;
        j++;
    }

    printer(arr1, n1);
    printer(arr2, n2);
    printer_point(pointers, n);
    return 0;
}
// 8
// 10 4 8 15 19 4 3 12
// 7
// 16 15 15 8 7 4 1

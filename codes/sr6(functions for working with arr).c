#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ZeroArray(int* array, int size) {
    for (int i=0; i<size; i++) {
        array[i] = 0;
    }
}

void FillArray(int* array, int size) {
    for (int i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }
}

void FillArrayWithRandom(int* array, int size, int minValue, int maxValue) {
    srand(time(NULL));
    for (int i=0; i<size; i++) {
        array[i] = (rand() % (maxValue - minValue + 1)) + minValue;
    }
}

void PrintArray(int* array, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

float average(int* array, int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += array[i];
    }
    return (float) sum / size;
}

int SumOfRange(int* start, int* end) {
    int sum = 0;
    int* current = start;
    while (current <= end) {
        sum += *(current++);
    }
    return sum;
}

int main() {
    const int size1 = 7;
    const int size2 = 8;
    const int size3 = 10;
    int arr1[size1];
    int arr2[size2];
    int arr3[size3];

    int arr[21] = {0};

    int minValue = 10;
    int maxValue = 30;

    // FillArrayWithRandom(arr1, size1, minValue, maxValue);
    // FillArrayWithRandom(arr2, size2, minValue, maxValue);
    // FillArrayWithRandom(arr3, size3, minValue, maxValue);
    
    FillArray(arr1, size1);
    FillArray(arr2, size2);
    FillArray(arr3, size3);
    
    int start, end;
    scanf("%d %d", &start, &end);
    
    for (int i=0; i<size1; i++) {
        arr[arr1[i] - minValue]++;
    }
    for (int i=0; i<size2; i++) {
        arr[arr2[i] - minValue]++;
    }
    for (int i=0; i<size3; i++) {
        arr[arr3[i] - minValue]++;
    }

	printf("%.1f %.1f %.1f\n", average(arr1, size1), average(arr2, size2), average(arr3, size3));
	printf("%d\n", SumOfRange(arr3+start-1, arr3+end));
	
	int a = 0;
	for (int i=0; i<maxValue-minValue+1; i++) {
	    if (arr[i] == 0) {
	        a = i;
	        break;
	    }
	}
	
    for (int i=0; i<maxValue-minValue+1; i++) {
        if (i == a) printf("%d", i + minValue);
        else if (arr[i] == 0) printf(" %d", i + minValue);
    }
    printf("\n");
    return 0;
}
// 24 12 26 13 14 10 23
// 10 27 24 17 18 12 16 29
// 21 30 19 29 25 16 11 24 22 13
// 5 10

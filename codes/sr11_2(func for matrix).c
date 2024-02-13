#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1. Заполнение матрицы случайными числами
void fill_matrix_rand(int m, int n, int matrix[][n], int minVal, int maxVal) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
}

//2. Вывод матрицы
void printer(int m, int n, int arr[][n]) {
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) printf("%3d", arr[i][j]);
	    printf("\n");
	}
}

//3. Считывание матрицы из файла
int** read_matrix_from_file(const char* filename, int* m, int* n) {
    FILE* file = fopen(filename, "r"); 

    if (file == NULL) {
        printf("Не удалось открыть файл для чтения\n");
        return NULL;
    }

    fscanf(file, "%d %d", m, n);

    int matrix[*m][*n];
    for (int i = 0; i < *m; i++) 
        for (int j = 0; j < *n; j++) fscanf(file, "%d", &matrix[i][j]);

    fclose(file);
    return matrix;
}

//4. Транспонирование
void transpose_matrix(int m, int n, int matrix[][n], int transposed[][m]) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            transposed[j][i] = matrix[i][j];
}

//5. Сложение матриц
int add_matrix(int m1, int n1, int m2, int n2, int mat1[][n1], int mat2[][n2], int result[][n2]) {
    int i, j;
	if (m1 != m2 && n1 != n2) return 1;
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
    return 0;
}

//6. Умножение матриц
int mult_matrix(int m1, int n1, int m2, int n2, int A[][n1], int B[][n2], int result[][n2]) {
	if (n1 != m2) return 1;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int x = 0; x < n1; x++) result[i][j] += A[i][x] * B[x][j];
        }
    }
    return 0;
}

//7. Возведение матрицы в степень
int power_matrix(int m, int n, int p, int A[][n], int result[][n]) {
	if (n != m) return 1;
    for (int i = 0; i < p; i++)
        mult_matrix(n, n, n, n, A, A, result);
    return 0;
}

int main(void) {
	int m1, n1, m2, n2;
	scanf("%d %d", &m1, &n1);
	
	int A[m1][n1];
	for (int i = 0; i < m1; i++)
	    for (int j = 0; j < n1; j++) scanf("%d", &A[i][j]);
	
	scanf("%d %d", &m2, &n2);
	int B[m2][n2];
	for (int i = 0; i < m2; i++)
	    for (int j = 0; j < n2; j++) scanf("%d", &B[i][j]);;
	
// 	printer(m1, n1, A);
// 	printf("\n");
// 	printer(m2, n2, B);
// 	printf("\n");
	
	
	int AB[m1][n2]; //A*B
	if (mult_matrix(m1, n1, m2, n2, A, B, AB)) {
	    printf("!2\n");
	    return 0;
	}
	
	int AB2[m1][n2]; //(A*B)^2
	if (power_matrix(m1, n2, 2, AB, AB2)) {
	    printf("!3\n");
	    return 0;
	}
	
	int At[n1][m1]; //At - транспонированная
	transpose_matrix(m1, n1, A, At); 
	
	int AAt[m1][m1]; //A*At
	if (mult_matrix(m1, n1, n1, m1, A, At, AAt)) {
	    printf("!2\n");
	    return 0;
	}
	
	int ans[m1][m1]; //(А*В)^2 + А*Аt
	if (add_matrix(m1, n2, m1, m1, AB2, AAt, ans)) {
	    printf("!1\n");
	    return 0;
	}
	
	for (int i = 0; i < m1; i++) {
	    for (int j = 0; j < m1; j++) printf("%6d", ans[i][j]);
	    printf("\n");
	}
	//printf("\n");
	
	return 0;
}
/*
3 4
3 2 4 1 5 2 1 4 1 3 4 2
4 3
2 4 5 3 2 1 4 3 3 1 5 2
*/
